#include "Queue.h"
#include <gtest.h>
#include <stdexcept>

TEST(Queue, can_add_task_to_queue) {
    Queue queue;
    Task task(5, 3);  // Создаем задачу с длительностью 5 и требующимися 3 узлами

    EXPECT_NO_THROW(queue.addTask(task));  // Проверяем, что добавление задачи не вызывает исключений
}
TEST(Queue, has_tasks_when_queue_is_not_empty) {
    Queue queue;
    Task task(5, 3);

    queue.addTask(task);  // Добавляем задачу в очередь

    EXPECT_TRUE(queue.hasTasks());  // Очередь должна содержать задачи
}

TEST(Queue, has_no_tasks_when_queue_is_empty) {
    Queue queue;

    EXPECT_FALSE(queue.hasTasks());  // Очередь не должна содержать задачи
}
TEST(Queue, can_get_next_task_from_queue) {
    Queue queue;
    Task task(5, 3);

    queue.addTask(task);  // Добавляем задачу в очередь

    Task retrievedTask = queue.getNextTask();  // Получаем задачу из очереди
    EXPECT_EQ(retrievedTask.duration, 5);  // Проверяем, что задача имеет ожидаемое время
    EXPECT_EQ(retrievedTask.nodesRequired, 3);  // Проверяем, что задача имеет ожидаемое количество узлов
}
TEST(Queue, throws_when_getting_task_from_empty_queue) {
    Queue queue;

    EXPECT_THROW(queue.getNextTask(), std::runtime_error);  // Ожидаем исключение типа std::runtime_error
}
