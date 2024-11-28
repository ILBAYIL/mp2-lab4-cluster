#include "ClusterManager.h"
#include <gtest.h>

TEST(ClusterManager, can_create_with_valid_node_count) {
    ClusterManager manager(5);  // ������� ������� � 5 ������
    EXPECT_EQ(manager.getTotalTasks(), 0);  // ����� ���������� ����� ������ ���� 0 ����� ��������
}
TEST(ClusterManager, can_add_task_to_queue) {
    ClusterManager manager(5);
    Task task(10, 3);  // ������ � 10 ������� � 3 ���������� ������

    manager.addTaskToQueue(task);  // ��������� ������ � �������

    EXPECT_EQ(manager.getTotalTasks(), 1);  // �������, ��� ���������� ����� ����� 1
}
TEST(ClusterManager, can_process_tasks) {
    ClusterManager manager(5);
    Task task(10, 3);  // ������, ��������� 3 ����

    manager.addTaskToQueue(task);  // ��������� ������
    manager.processTasks();  // ������������ ������

    EXPECT_EQ(manager.getCompletedTasks(), 1);  // �������, ��� ������ ����� ���������
}
TEST(ClusterManager, task_fails_when_not_enough_nodes) {
    ClusterManager manager(2);  // ������� � 2 ������
    Task task(10, 3);  // ������, ��������� 3 ����

    manager.addTaskToQueue(task);
    manager.processTasks();  // ������������ ������

    EXPECT_EQ(manager.getFailedTasks(), 1);  // �������, ��� ������ �� ����� ���������
}
TEST(ClusterManager, can_count_completed_tasks) {
    ClusterManager manager(3);  // ������� � 3 ������
    Task task1(10, 2);
    Task task2(5, 1);

    manager.addTaskToQueue(task1);
    manager.addTaskToQueue(task2);
    manager.processTasks();  // ������������ ������

    EXPECT_EQ(manager.getCompletedTasks(), 2);  // �������, ��� ��� ������ ����� ���������
}
TEST(ClusterManager, can_print_statistics) {
    ClusterManager manager(3);
    Task task1(10, 2);
    Task task2(5, 1);

    manager.addTaskToQueue(task1);
    manager.addTaskToQueue(task2);
    manager.processTasks();

    testing::internal::CaptureStdout();  // ����������� �����
    manager.printStatistics();  // �������� ����������
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("����� ���������� ������:"), std::string::npos);  // ���������, ��� ���������� ��������
    EXPECT_NE(output.find("��������� �����:"), std::string::npos);
    EXPECT_NE(output.find("����������� �����:"), std::string::npos);
}
TEST(ClusterManager, can_visualize_cluster_state) {
    ClusterManager manager(3);
    Task task1(10, 2);
    Task task2(5, 1);

    manager.addTaskToQueue(task1);
    manager.addTaskToQueue(task2);
    manager.processTasks();

    testing::internal::CaptureStdout();  // ����������� �����
    manager.visualizeCluster();  // ������������� ��������� ��������
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("��������� ��������:"), std::string::npos);  // ���������, ��� ��������� ��������
}
