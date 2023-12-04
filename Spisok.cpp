#pragma once
#include <iostream>
#include <random>
#include <complex>
using namespace std;


namespace spisok {

	template <typename T>
	class note {
	private:
		note* _next;
		note* _prev;
		T* _val;
	public:
		note() { _next = nullptr; _prev = nullptr; _val = nullptr; }
		note(T data) { _next = nullptr; _prev = nullptr; _val = new T(data); }
		note(note* temp1, note* temp2, T data) { _next = temp1; _prev = temp2; _val = new T(data); }
		note(note<T>& another) { _next = another._next; _prev = another._prev; _val = new T(*another._val); }
		~note() { _next = nullptr; _prev = nullptr; delete _val; };
		note* get_n() { return _next; }
		note* get_p() { return _prev; }
		T* get_v() { return _val; }
		void set_n(note* next) { _next = next; }
		void set_p(note* prev) { _prev = prev; }
		void set_v(T* val) { _val = val; }
		friend ostream& operator<< (ostream& o, note<T>& t) { cout << *(t.get_v()) << " "; return o; }
		friend bool operator== (note<T> rhs, note<T> lhs) {
			if (*(rhs.get_v()) == *(lhs.get_v())) { return false; }
			else { return true; }
		}
		friend bool operator!= (note<T> rhs, note<T> lhs) {
			if (*(rhs.get_v()) == *(lhs.get_v())) { return true; }
			else { return false; }
		}
		void operator= (const note<T> lhs) { _next = lhs._next; _prev = lhs._prev; _val = lhs._val; }

	};

	template <typename T>
	class twolist {
	protected:
		note<T>* _head;
		note<T>* _end;
	public:

		twolist() { _head = nullptr; _end = nullptr; }

		twolist(const twolist& another) {
			_head = nullptr;
			_end = nullptr;
			note<T>* temp = another._head;
			this->push_end(new note<T>(*temp));
			temp = temp->get_n();
			while (temp != nullptr) {
				note<T>* nw = new note<T>(*temp);
				this->push_end(nw);
				temp = temp->get_n();
			}
		}

		twolist(int size, T min, T max) {
			_head, _end = nullptr;
			for (int i = 0; i < size; i++) {
				this->push_end(new note<T>(random(min, max)));
			}
		}

		T random(T min, T max) {
			std::random_device random_device;
			std::mt19937 generator(random_device());
			std::uniform_int_distribution<> distribution(min, max);
			T x = distribution(generator);
			return x;
		}

		void push_head(note<T>* start) {
			if (_head == nullptr) {
				_head = start;
				_end = start;
				start->set_n(nullptr);
				start->set_p(nullptr);
			}
			else {
				start->set_p(nullptr);
				start->set_n(_head);
				_head->set_p(start);
				_head = start;
			}
		}

		void push_end(note<T>* tail) {
			if (_end == nullptr) {
				_head = tail;
				_end = tail;
				tail->set_n(nullptr);
				tail->set_p(nullptr);
			}
			else {
				_end->set_n(tail);
				tail->set_n(nullptr);
				tail->set_p(_end);
				_end = tail;
			}
		}

		void push_head(twolist<T> start) {
			start._end->set_n(_head);
			_head->set_p(start._end);
			_head = start._head;
		}

		void push_end(twolist<T> list) {
			_end->set_n(list._head);
			list._head->set_p(_end);
			_end = list._end;
		}

		void pop_head() {
			_head->get_n()->set_p(nullptr);
			_head = _head->get_n();
		}

		void pop_end() {
			_end->get_p()->set_n(nullptr);
			_end = _end->get_p();
		}


		void deleate(T val) {
			note<T>* temp = _head;
			int len = this->len();
			for (int i = 0; i < len; i++) {
				if (*(temp->get_v()) == val) {
					if (temp == _head) { this->pop_head(); }
					else {
						if (temp == _end) { this->pop_end(); }
						else
						{
							temp->get_p()->set_n(temp->get_n());
							temp->get_n()->set_p(temp->get_p());
						}
					}

				}
				temp = temp->get_n();
			}
		}

		~twolist() = default;

		friend ostream& operator<< (ostream& out, twolist<T>& list) {
			note<T>* start = list._head;
			while (start != nullptr) {
				cout << *start;
				start = start->get_n();
			}
			return out;
		}

		note<T>* operator[](int index) {
			note<T>* start = _head;
			if (index > this->len()) { throw runtime_error("Index is out of range"); }
			if (start == nullptr && index == 0) { return _head; }
			for (int i = 0; i < index; i++) { start = start->get_n(); }
			return start;
		}

		int len() {
			if (_head == nullptr)
				return 0;
			int len = 0;
			note<T>* temp = _head->get_n();
			while (temp != nullptr) {
				len += 1;
				temp = temp->get_n();
			}
			return len + 1;
		}

		note<T>* get_end() { return _end; }
	};

	void sum_num(twolist<int>* lhs, twolist<int>* rhs) {
		note<int>* left = lhs->get_end();
		note<int>* right = rhs->get_end();
		int overf = 0;
		while (left != nullptr && right != nullptr) {
			int a = *(left->get_v()) + *(right->get_v());
			cout << a;
			left->set_v(&a);
			left = left->get_p();
			right = right->get_p();
		}
		
	}

}