#include "Task.h"
#include <gtest.h>

TEST(Task, can_create_task_with_valid_parameters) {
    // �������� ������ � ������������������ 10 � ��������� ����������� ����� 3
    Task task(10, 3);

    EXPECT_EQ(task.duration, 10);  // ��������� ����������������� ������
    EXPECT_EQ(task.nodesRequired, 3);  // ��������� ���������� ��������� �����
}
TEST(Task, can_create_task_with_zero_values) {
    // �������� ������ � ������� ������������������ � ������� ����������� �����
    Task task(0, 0);

    EXPECT_EQ(task.duration, 0);  // ����������������� ������ ������ ���� 0
    EXPECT_EQ(task.nodesRequired, 0);  // ���������� ��������� ����� ������ ���� 0
}
TEST(Task, can_create_task_with_negative_values) {
    // �������� ������ � �������������� ����������
    Task task(-5, -2);

    EXPECT_EQ(task.duration, -5);  // ����������������� ������ ������ ���� -5
    EXPECT_EQ(task.nodesRequired, -2);  // ���������� ��������� ����� ������ ���� -2
}
TEST(Task, can_create_task_with_large_values) {
    // �������� ������ � �������� ����������
    Task task(1000000, 1000);

    EXPECT_EQ(task.duration, 1000000);  // ����������������� ������ ������ ���� 1000000
    EXPECT_EQ(task.nodesRequired, 1000);  // ���������� ��������� ����� ������ ���� 1000
}
