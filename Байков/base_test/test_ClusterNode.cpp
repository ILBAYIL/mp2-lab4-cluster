#include "ClusterNode.h"
#include <gtest.h>

TEST(ClusterNode, can_create_cluster_node) {
    ClusterNode node;  // ������� ���� ��������
    EXPECT_FALSE(node.isBusy);  // ���� �� ������ ���� ����� ��� �������������
    EXPECT_EQ(node.remainingTime, 0);  // ����� ���������� ������ ������ ���� ����� 0
}
TEST(ClusterNode, assign_task_to_node) {
    ClusterNode node;
    node.assignTask(5);  // ��������� ������ �� 5 ������

    EXPECT_TRUE(node.isBusy);  // ���� ������ ���� �����
    EXPECT_EQ(node.remainingTime, 5);  // ���������� ����� ������ ���� ����� 5
}
TEST(ClusterNode, process_tick_for_idle_node) {
    ClusterNode node;
    node.processTick();  // ������������ ���� ��� ���������� ����

    EXPECT_FALSE(node.isBusy);  // ���� �� ������ ����� �����
    EXPECT_EQ(node.remainingTime, 0);  // ����� ���������� ������ ������ �������� 0
}
TEST(ClusterNode, process_tick_for_busy_node) {
    ClusterNode node;
    node.assignTask(3);  // ��������� ������ �� 3 �����

    node.processTick();  // ������ ����
    EXPECT_TRUE(node.isBusy);  // ���� ������ ���� �����
    EXPECT_EQ(node.remainingTime, 2);  // ����� ���������� ������ ������ ����������� �� 1

    node.processTick();  // ������ ����
    EXPECT_TRUE(node.isBusy);  // ���� ��-�������� �����
    EXPECT_EQ(node.remainingTime, 1);  // ����� ���������� ������ ������ ����������� �� 1

    node.processTick();  // ������ ����
    EXPECT_FALSE(node.isBusy);  // ���� ������ ������������
    EXPECT_EQ(node.remainingTime, 0);  // ����� ���������� ������ ������ ����� 0
}
TEST(ClusterNode, process_tick_for_completed_task) {
    ClusterNode node;
    node.assignTask(1);  // ��������� ������ �� 1 ����

    node.processTick();  // ������ ����
    EXPECT_FALSE(node.isBusy);  // ���� ������ ������������
    EXPECT_EQ(node.remainingTime, 0);  // ����� ���������� ������ ������ ���� 0

    node.processTick();  // ������������ ���� ����� ���������� ������
    EXPECT_FALSE(node.isBusy);  // ���� ������ ���������� ���������
    EXPECT_EQ(node.remainingTime, 0);  // ����� ���������� ������ ������ �������� 0
}
