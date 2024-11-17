#include <scene_manager.h>

int main() {
	setlocale(LC_ALL, "rus");
	SceneManager sceneManager;
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	while (sceneManager.getScene() != Scene::EXIT) {
		sceneManager.playScene();
	}
	return 0;
}