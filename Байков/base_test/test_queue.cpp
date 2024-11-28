#include "Queue.h"
#include <gtest.h>
#include <stdexcept>

TEST(Queue, can_add_task_to_queue) {
    Queue queue;
    Task task(5, 3);  // ������� ������ � ������������� 5 � ������������ 3 ������

    EXPECT_NO_THROW(queue.addTask(task));  // ���������, ��� ���������� ������ �� �������� ����������
}
TEST(Queue, has_tasks_when_queue_is_not_empty) {
    Queue queue;
    Task task(5, 3);

    queue.addTask(task);  // ��������� ������ � �������

    EXPECT_TRUE(queue.hasTasks());  // ������� ������ ��������� ������
}

TEST(Queue, has_no_tasks_when_queue_is_empty) {
    Queue queue;

    EXPECT_FALSE(queue.hasTasks());  // ������� �� ������ ��������� ������
}
TEST(Queue, can_get_next_task_from_queue) {
    Queue queue;
    Task task(5, 3);

    queue.addTask(task);  // ��������� ������ � �������

    Task retrievedTask = queue.getNextTask();  // �������� ������ �� �������
    EXPECT_EQ(retrievedTask.duration, 5);  // ���������, ��� ������ ����� ��������� �����
    EXPECT_EQ(retrievedTask.nodesRequired, 3);  // ���������, ��� ������ ����� ��������� ���������� �����
}
TEST(Queue, throws_when_getting_task_from_empty_queue) {
    Queue queue;

    EXPECT_THROW(queue.getNextTask(), std::runtime_error);  // ������� ���������� ���� std::runtime_error
}
