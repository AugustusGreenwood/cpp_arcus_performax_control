#ifndef TRANSFERQUEUE_H
#define TRANSFERQUEUE_H

#include <condition_variable>
#include <mutex>
#include <optional>
#include <queue>

template <typename T> class TransferQueue {
  public:
	void push(const T &value) {
		std::lock_guard<std::mutex> lock(mtx);
		queue.push(value);
		cv.notify_one();
	}

	T pop() {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [this]() { return !queue.empty(); });
		T value = queue.front();
		queue.pop();
		return value;
	}

	std::optional<T> try_pop() {
		std::lock_guard<std::mutex> lock(mtx);
		if (queue.empty()) {
			return std::nullopt;
		}

		T value = queue.front();
		queue.pop();
		return value;
	}

	bool empty() {
		std::lock_guard<std::mutex> lock(mtx);
		return queue.empty();
	}

	size_t size() {
		std::lock_guard<std::mutex> lock(mtx);
		return queue.size();
	}

  private:
	std::queue<T> queue;
	std::mutex mtx;
	std::condition_variable cv;
};

#endif // !TRANSFERQUEUE_H
