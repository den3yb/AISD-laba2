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
		T _val;
	public:
		note() { _next = nullptr; _prev = nullptr; _val = 0; }
		node(T data) { _next = nullptr; _prev = nullptr; _val = data; }
		note(note* temp1, note* temp2, T data) { _next = temp1; _prev = temp2; _val = data; }
		note(note<T>& another){ _next = another._next; _prev = another._prev; _val = another._val; }
		~note() = default;
		note* get_n() { return _next; }
		note* get_p() { return _prev; }
		note* get_v() { return _val; }
		void set_n(note* next) { _next = next; }
		void set_p(note* prev) { _prev = prev; }
		void set_v(T val) {_val = val; }
		friend std::ostream& operator<< (std::ostream o, note<T>& t) { std::cout << t->get_v(); return o; }
		friend bool operator== (note<T> rhs, note<T> lhs) {
			if (rhs.get_v() == lhs.get_v()) { return false; }
			else { return true; }
		}
		friend bool operator!= (note<T> rhs, note<T> lhs) {
			if (rhs.get_v() == lhs.get_v()) { return true; }
			else { return false; }
		}
	};

	template <typename T>
	class twolist {
	protected:

		note<T>* _head;
		note<T>* _end;
	public:

		twolist() { _head(nullptr), _end(nullptr); }

		twolist(const twolist& another) {
			_head = nullptr;
			_end = nullptr;
			note<T>* temp = another._head;
			this->in_end(new note<T>(*temp));
			temp = temp->get_n();
			while (temp != nullptr) {
				note<T>* nw = new note<T>(*temp);
				this->in_end(nw);
				temp = temp->get_n();
			}
		}



		void push_head(note<T>* start) {
			_head->set_p(start);
			start->set_p(nullptr);
			start->set_n(_end);
			_head = start;
		}

		void push_end(note<T>* tail) {
			_end->set_n(tail);
			tail->set_n(nullptr);
			tail->set_p(_end);
			_end = tail;
		}

		void push_head(twolist<T> start) {
			start._end->set_n(_head);
			_head->set_p(start._end);
			_head = start;
		}

		void push_end(twolist<T> list) {
			_end->set_n(list);
			list._head->set_p(_end);
			_end = list;
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
			note<T> temp = _head;
			int len = this->len();
			for (int i = 0; i < len; i++) {
				if (temp->get_v() == val) {
					if (temp == _head){this->pop_head();}
					else {
						if (temp == _end){ this->pop_end(); }
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

		friend std::ostream& operator<< (std::ostream& out, const twolist<T>& list) {
			note<T>* start = list._head;
			while (_head != nullptr) {
				cout << *start << " ";
				start = start->get_next();
			}
			cout << *start->get_d() << endl;
			return out;
		}

		note<T>* operator[](int index) {
			note<T>* start = _head;
			if (index>this->len()) { throw runtime_error("Index is out of range"); }
			if (start == nullptr && index == 0) { return _head; }
			for (int i = 0; i < index; i++) {start = start->get_n();}
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
			return len+1;
		}

	};


}