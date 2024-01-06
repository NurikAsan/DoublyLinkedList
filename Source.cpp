
#include <iostream>
#include<Windows.h>
using namespace std;

int idGenerator;

struct Node {
	int item;
	int key;
	Node* prev;
	Node* next;
};
struct DoublyLinkedList {
	Node* head;
	Node* tail;
	int size;

	DoublyLinkedList() {
		idGenerator = 1;
		head = tail = nullptr;
		size = 0;
	}


	void push_back(int val) {  
		Node* tmp = new Node;
		tmp->item = val;
		tmp->key = (size + 5) * 7 + idGenerator++; 
		tmp->next = nullptr; tmp->prev = nullptr;

		if (head == nullptr) {
			head = tmp;
			head->prev = nullptr;
		}
		else {
			tail->next = tmp;
			tmp->prev = tail;
		}
		tail = tmp;
		size++;
	}

	// Function -> insert by position after value
	void insert_after_position(int position, int val) {
		if (!(position < 0 || position >= size)) {  // check -> correct position

			Node* tmp = new Node;
			tmp->item = val;
			tmp->key = (size + 5) * 7 + idGenerator++;
			tmp->next = nullptr; tmp->prev = nullptr;

			Node* node = head;
			int index = 0;
			while (index != position) {
				node = node->next;
				++index;
			}

			// logic switch nodes
			tmp->next = node->next;
			if (node->next != nullptr)
				node->next->prev = tmp;
			node->next = tmp;
			tmp->prev = node;

			if (position == size - 1)
				tail = tmp;

			size++;
		}
		else cout << "Incorrect position" << endl;
	}

	// Function -> insert by position before value
	void insert_before_position(int position, int val) {
		if (!(position <= 0 || position >= size)) {  // check -> correct position
			Node* tmp = new Node;
			tmp->item = val;
			tmp->key = (size + 5) * 7 + idGenerator++;
			tmp->next = nullptr; tmp->prev = nullptr;

			Node* node = head;
			int index = 0;
			while (index != position - 1) {
				node = node->next;
				++index;
			}

			tmp->next = node;
			if (node->prev == nullptr)
				head = tmp;
			else
				node->prev->next = tmp;

			tmp->prev = node->prev;
			node->prev = tmp;

			size++;
		}
		else cout << "Incorrect position" << endl;
	}

	void remove_after_position(int position) {
		if (!(position < 0 || position >= size)) {  // check -> correct position

			Node* node = head;
			int index = 0;
			while (index != position) {
				node = node->next;
				++index;
			}

			// check -> item last item?
			if (node->next == nullptr) {
				cout << "Нет соседнего элемента" << endl;
				return;
			}

			Node* nodeToRemove = node->next;
			node->next = nodeToRemove->next;
			if (nodeToRemove->next != nullptr)
				nodeToRemove->next->prev = node;
			else
				tail = node;

			delete nodeToRemove;
			size--;
		}
		else cout << "Incorrect position" << endl;
	}
	void remove_before_position(int position) {
		if (!(position < 0 || position >= size)) {  // check -> correct position

			if (position == 0) {
				cout << "Нет предшествующего элемента" << endl;
				return;
			}

			Node* node = head;
			int index = 0;
			while (index != position - 1) {
				node = node->next;
				++index;
			}


			node->next->prev = node->prev;
			if (node->prev != nullptr)
				node->prev->next = node->next;
			else
				head = node->next;

			delete node;
			size--;
		}
		else cout << "Incorrect position" << endl;
	}
	Node* search_before_position(int position) {
		if (!(position < 0 || position >= size)) {  // check -> correct position

			Node* node = head;
			int index = 0;
			while (index != position) {
				node = node->next;
				++index;
			}

			if (node->prev == nullptr) {
				cout << "Нет предшествующего элемента" << endl;
				return nullptr;
			}

			return node->prev;
		}
		else cout << "Incorrect position" << endl;
		return nullptr;
	}
	Node* search_after_position(int position) {
		if (!(position < 0 || position >= size)) {  // check -> correct position

			Node* node = head;
			int index = 0;
			while (index != position) {
				node = node->next;
				++index;
			}

			if (node->next == nullptr) {
				cout << "Нет соседнего элемента" << endl;
				return nullptr;
			}

			return node->next;
		}
		else cout << "Incorrect position" << endl;
		return nullptr;
	}

	// output Nurs Function
	void print() {
		if (head != nullptr) {
			int pos = 0;
			Node* tmp = head;

			while (tmp != NULL) {
				cout << tmp->item << " Key - " << tmp->key << " Position - " << pos++ << endl;
				tmp = tmp->next;
			}

		}
		else
			cout << "List empty" << endl;
	}
	void print_reverse() {
		if (head != nullptr) {
			Node* tmp = tail;

			while (tmp != NULL) {
				cout << tmp->item << " Key - " << tmp->key << endl;
				tmp = tmp->prev;
			}

		}
		else
			cout << "List empty" << endl;
	}
};


void print_menu();  //-> Nurs Menu

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	print_menu();

	return 0;
}


void print_menu() {
	unsigned short choose;   // variable for choose menu
	int value, position;
	DoublyLinkedList list;
	while (true) {
		cout << "Выберите операцию:" << endl;  // -> Choose operation
		cout << "1. Добавление" << endl;
		cout << "2. Add after value" << endl; cout << "3. Add after position" << endl;
		cout << "4. Add before value" << endl; cout << "5. Add before position" << endl;
		cout << "6. Remove by value" << endl; cout << "7. Remove after position" << endl;
		cout << "\033[1;31m8. Выход с программы\033[0m" << endl;
		cout << "9.  Remove after value" << endl; cout << "10. Remove before position" << endl;
		cout << "11. Remove before value" << endl;
		cout << "12. Search before position" << endl; cout << "13. Search before value" << endl;
		cout << "14. Search after position" << endl; cout << "15. Search after value" << endl;
		cout << "16. Output" << endl; cout << "17. Output reverse" << endl;
		cout << "18. Очистка" << endl;

		cin >> choose;
		switch (choose) {
		case 1: {
			system("cls");
			cout << "Введите элемент: "; cin >> value;
			list.push_back(value);
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			cout << "Введите позицию после которого, нужно добавить значение: "; cin >> position;
			cout << "Введите элемент: "; cin >> value;
			list.insert_after_position(position, value);
			break;
		}
		case 6: {
			system("cls");
			list.print_reverse();
			break;
		}
		case 7: {
			cout << "Введите позицию после которого, нужно удалить значение: "; cin >> position;
			list.remove_after_position(position);
			break;
		}
		case 10: {
			cout << "Введите позицию перед которым, нужно удалить значение: "; cin >> position;
			list.remove_before_position(position);
			break;
		}
		case 12: {
			// Not FINISH!
			cout << "Введите позицию перед которым, нужно найти значение: "; cin >> position;
			Node* node = list.search_before_position(position);
			cout << node->item << " Key - " << node->key << endl;
			break;
		}
		case 14: {
			// Not FINISH!
			cout << "Введите позицию после которого, нужно найти значение: "; cin >> position;
			Node* node = list.search_after_position(position);
			cout << node->item << " Key - " << node->key << endl;
			break;
		}
		case 16: {
			system("cls");
			list.print();
			break;
		}
		case 17: {
			cout << "Введите позицию перед которым, нужно добавить значение: "; cin >> position;
			cout << "Введите элемент: "; cin >> value;
			list.insert_before_position(position, value);
			break;
		}
		default: break;
		}
	}
}