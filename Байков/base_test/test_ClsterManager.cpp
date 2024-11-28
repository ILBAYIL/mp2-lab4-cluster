#include "ClusterManager.h"
#include <gtest.h>

TEST(ClusterManager, can_create_with_valid_node_count) {
    ClusterManager manager(5);  // Создаем кластер с 5 узлами
    EXPECT_EQ(manager.getTotalTasks(), 0);  // Общее количество задач должно быть 0 после создания
}
TEST(ClusterManager, can_add_task_to_queue) {
    ClusterManager manager(5);
    Task task(10, 3);  // Задача с 10 тактами и 3 требуемыми узлами

    manager.addTaskToQueue(task);  // Добавляем задачу в очередь

    EXPECT_EQ(manager.getTotalTasks(), 1);  // Ожидаем, что количество задач стало 1
}
TEST(ClusterManager, can_process_tasks) {
    ClusterManager manager(5);
    Task task(10, 3);  // Задача, требующая 3 узла

    manager.addTaskToQueue(task);  // Добавляем задачу
    manager.processTasks();  // Обрабатываем задачи

    EXPECT_EQ(manager.getCompletedTasks(), 1);  // Ожидаем, что задача будет выполнена
}
TEST(ClusterManager, task_fails_when_not_enough_nodes) {
    ClusterManager manager(2);  // Кластер с 2 узлами
    Task task(10, 3);  // Задача, требующая 3 узла

    manager.addTaskToQueue(task);
    manager.processTasks();  // Обрабатываем задачи

    EXPECT_EQ(manager.getFailedTasks(), 1);  // Ожидаем, что задача не будет выполнена
}
TEST(ClusterManager, can_count_completed_tasks) {
    ClusterManager manager(3);  // Кластер с 3 узлами
    Task task1(10, 2);
    Task task2(5, 1);

    manager.addTaskToQueue(task1);
    manager.addTaskToQueue(task2);
    manager.processTasks();  // Обрабатываем задачи

    EXPECT_EQ(manager.getCompletedTasks(), 2);  // Ожидаем, что обе задачи будут выполнены
}
TEST(ClusterManager, can_print_statistics) {
    ClusterManager manager(3);
    Task task1(10, 2);
    Task task2(5, 1);

    manager.addTaskToQueue(task1);
    manager.addTaskToQueue(task2);
    manager.processTasks();

    testing::internal::CaptureStdout();  // Захватываем вывод
    manager.printStatistics();  // Печатаем статистику
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Общее количество тактов:"), std::string::npos);  // Проверяем, что статистика выведена
    EXPECT_NE(output.find("Выполнено задач:"), std::string::npos);
    EXPECT_NE(output.find("Невыполнено задач:"), std::string::npos);
}
TEST(ClusterManager, can_visualize_cluster_state) {
    ClusterManager manager(3);
    Task task1(10, 2);
    Task task2(5, 1);

    manager.addTaskToQueue(task1);
    manager.addTaskToQueue(task2);
    manager.processTasks();

    testing::internal::CaptureStdout();  // Захватываем вывод
    manager.visualizeCluster();  // Визуализируем состояние кластера
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Состояние кластера:"), std::string::npos);  // Проверяем, что состояние выведено
}
