#include "ClusterNode.h"
#include <gtest.h>

TEST(ClusterNode, can_create_cluster_node) {
    ClusterNode node;  // Создаем узел кластера
    EXPECT_FALSE(node.isBusy);  // Узел не должен быть занят при инициализации
    EXPECT_EQ(node.remainingTime, 0);  // Время выполнения задачи должно быть равно 0
}
TEST(ClusterNode, assign_task_to_node) {
    ClusterNode node;
    node.assignTask(5);  // Назначаем задачу на 5 тактов

    EXPECT_TRUE(node.isBusy);  // Узел должен быть занят
    EXPECT_EQ(node.remainingTime, 5);  // Оставшееся время должно быть равно 5
}
TEST(ClusterNode, process_tick_for_idle_node) {
    ClusterNode node;
    node.processTick();  // Обрабатываем такт для свободного узла

    EXPECT_FALSE(node.isBusy);  // Узел не должен стать занят
    EXPECT_EQ(node.remainingTime, 0);  // Время выполнения задачи должно остаться 0
}
TEST(ClusterNode, process_tick_for_busy_node) {
    ClusterNode node;
    node.assignTask(3);  // Назначаем задачу на 3 такта

    node.processTick();  // Первый такт
    EXPECT_TRUE(node.isBusy);  // Узел должен быть занят
    EXPECT_EQ(node.remainingTime, 2);  // Время выполнения задачи должно уменьшиться на 1

    node.processTick();  // Второй такт
    EXPECT_TRUE(node.isBusy);  // Узел по-прежнему занят
    EXPECT_EQ(node.remainingTime, 1);  // Время выполнения задачи должно уменьшиться на 1

    node.processTick();  // Третий такт
    EXPECT_FALSE(node.isBusy);  // Узел должен освободиться
    EXPECT_EQ(node.remainingTime, 0);  // Время выполнения задачи должно стать 0
}
TEST(ClusterNode, process_tick_for_completed_task) {
    ClusterNode node;
    node.assignTask(1);  // Назначаем задачу на 1 такт

    node.processTick();  // Первый такт
    EXPECT_FALSE(node.isBusy);  // Узел должен освободиться
    EXPECT_EQ(node.remainingTime, 0);  // Время выполнения задачи должно быть 0

    node.processTick();  // Обрабатываем такт после завершения задачи
    EXPECT_FALSE(node.isBusy);  // Узел должен оставаться свободным
    EXPECT_EQ(node.remainingTime, 0);  // Время выполнения задачи должно остаться 0
}
