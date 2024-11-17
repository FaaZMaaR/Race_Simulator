#include <scene_manager.h>

SceneManager::SceneManager() : scene{ Scene::PICK_RACE }, raceType{ Type::GROUND }, race{}, raceResults{} {}

SceneManager::~SceneManager() {
	delete race;
	delete[] raceResults;
}

Scene SceneManager::getScene() const {
	return scene;
}

void SceneManager::fillRaceResults() {
	delete[] raceResults;
	raceResults = new RaceResult[race->getVehiclesCount()];
	for (int i = 0; i < race->getVehiclesCount(); i++) {
		raceResults[i].vehicleName = (*race)[i].getName();
		raceResults[i].totalTime = (*race)[i].getTotalTime(race->getDistance());
	}
	for (int i = 0; i < race->getVehiclesCount() - 1; i++) {
		for (int j = 0; j < race->getVehiclesCount() - 1 - i; j++) {
			if (raceResults[j].totalTime > raceResults[j + 1].totalTime) {
				RaceResult tmp = raceResults[j];
				raceResults[j] = raceResults[j + 1];
				raceResults[j + 1] = tmp;
			}
		}
	}
}

bool SceneManager::checkVehicle(const Vehicle& v) {
	for (int i = 0; i < race->getVehiclesCount(); i++) {
		if ((*race)[i].getName() == v.getName()) return true;
	}
	return false;
}

bool SceneManager::checkRaceType(const Vehicle& v) {
	return ((race->getType() == v.getType()) || race->getType() == Type::GROUND_AIR);
}

void SceneManager::pickRaceType() {
	std::cout << "1. Гонка для наземного транспорта"
		<< "\n2. Гонка для воздушного транспорта"
		<< "\n3. Гонка для наземного и воздушного транспорта"
		<< "\nВыберите тип гонки: ";
	int choice;
	while (true) {
		std::cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3) {
			std::cout << "Неверный тип. Выберите тип гонки: ";
		}
		else {
			raceType = static_cast<Type>(choice);
			break;
		}
	}
	scene = Scene::DEFINE_DISTANCE;
}

void SceneManager::createRace() {
	std::cout << "\nУкажите длину дистанции (должна быть положительна): ";
	double dist;
	while (true) {
		std::cin >> dist;
		if (dist <= 0) {
			std::cout << "Дистанция некорректна. Укажите длину дистанции (должна быть положительна): ";
		}
		else {
			break;
		}
	}
	race = new Race(raceType, dist);
	scene = Scene::REG_VEHICLE_OR_START_RACE;
}

void SceneManager::registerOrStart() {
	if (race->getVehiclesCount() < 2) {
		std::cout << "\nДолжно быть зарегистрировано хотя бы 2 транспортных средства"
			<< "\n1. Зарегистрировать транспорт"
			<< "\nВыберите действие: ";
	}
	else {
		std::cout << "\n1. Зарегистрировать транспорт"
			<< "\n2. Начать гонку"
			<< "\nВыберите действие: ";
	}
	int choice;
	while (true) {
		std::cin >> choice;
		if (choice != 1 && !(choice == 2 && race->getVehiclesCount() >= 2)) {
			std::cout << "Неверное действие. Выберите действие: ";
		}
		else if (choice == 1) {
			scene = Scene::PICK_VEHICLE;
			break;
		}
		else if (choice == 2) {
			scene = Scene::RACE_RESULTS;
			break;
		}
	}
}

void SceneManager::pickVehicle() {
	std::cout << "\n" << race->getName() << ". Расстояние: " << race->getDistance();
	if (race->getVehiclesCount() > 0) {
		std::cout << "\nЗарегистрированные транспортные средства: ";
		for (int i = 0; i < race->getVehiclesCount(); i++) {
			if (i < race->getVehiclesCount() - 1) {
				std::cout << (*race)[i].getName() << ", ";
			}
			else {
				std::cout << (*race)[i].getName();
			}				
		}
	}
	std::cout << "\n1. Верблюд"
		<< "\n2. Верблюд-быстроход"
		<< "\n3. Кентавр"
		<< "\n4. Ботинки-вездеходы"
		<< "\n5. Ковер-самолет"
		<< "\n6. Орел"
		<< "\n7. Метла"
		<< "\n0. Закончить регистрацию"
		<< "\nВыберите транспорт или 0 для окончания процесса регистрации: ";
	int choice;
	while (true) {
		std::cin >> choice;
		if (choice < 0 || choice>7) {
			std::cout << "Неверный вариант. Выберите транспорт или 0 для окончания процесса регистрации: ";
		}
		else {
			break;
		}
	}
	Vehicle* v = nullptr;
	switch (static_cast<VehicleType>(choice)) {
		case VehicleType::NONE:
			scene = Scene::REG_VEHICLE_OR_START_RACE;
			return;
		case VehicleType::CAMEL:
			v = new Camel();
			break;
		case VehicleType::SPEEDSTER_CAMEL:
			v = new SpeedsterCamel();
			break;
		case VehicleType::CENTAUR:
			v = new Centaur();
			break;
		case VehicleType::ROVER_BOOTS:
			v = new RoverBoots();
			break;
		case VehicleType::MAGIC_CARPET:
			v = new MagicCarpet();
			break;
		case VehicleType::EAGLE:
			v = new Eagle();
			break;
		case VehicleType::BROOM:
			v = new Broom();
			break;
	}
	if (checkVehicle(*v)) {
		std::cout << "\n" << v->getName() << " уже зарегистрирован!";
	}
	else if (!checkRaceType(*v)) {
		std::cout << "\n" << "Попытка зарегистрировать неправильный тип траспортного средства!";
	}
	else {
		race->addVehicle(v);
		std::cout << "\n" << v->getName() << " успешно зарегистрирован!";
	}
}

void SceneManager::showResults() {
	std::cout << "\nРезультаты гонки:\n";
	fillRaceResults();
	for (int i = 0; i < race->getVehiclesCount(); i++) {
		std::cout << i + 1 << ". " << raceResults[i].vehicleName << ". Время: " << raceResults[i].totalTime << std::endl;
	}
	scene = Scene::RACE_AGAIN;
}

void SceneManager::raceAgain() {
	std::cout << "\n1. Провести еще одну гонку"
		<< "\n2. Выйти"
		<< "\nВыберите действие: ";
	int choice;
	while (true) {
		std::cin >> choice;
		if (choice == 1) {
			scene = Scene::PICK_RACE;
			delete race;
			std::cout << std::endl;
			break;
		}
		else if (choice == 2) {
			scene = Scene::EXIT;
			break;
		}
		else {
			std::cout << "Неверное действие. Выберите действие: ";
		}
	}
}

void SceneManager::playScene() {
	switch (scene) {
		case Scene::PICK_RACE:		
			pickRaceType();		
			break;
		case Scene::DEFINE_DISTANCE:		
			createRace();		
			break;
		case Scene::REG_VEHICLE_OR_START_RACE:
			registerOrStart();
			break;
		case Scene::PICK_VEHICLE:
			pickVehicle();
			break;
		case Scene::RACE_RESULTS:
			showResults();
			break;
		case Scene::RACE_AGAIN:
			raceAgain();
			break;
	}	
}