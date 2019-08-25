#include "iostream"


class list_element {
public:
	list_element(int val = 0, list_element *ptr = nullptr):
		d(val), next(ptr) {}
	int d;
	list_element *next;
};


class list {
public:
	list():
		head(nullptr), cursor(nullptr) {}
	list(const int *arr, int n);
	list(const list &lst);

	void prepend(int n);
	int get_element() {return cursor->d;}
	void advance() {cursor = cursor->next;}
	void print();
	~list();
private:
	list_element *head, *cursor;
};


void
list::prepend(int n) {
	if (head == nullptr)
		cursor = head = new list_element(n, head);
	else
		head = new list_element(n, head);
}


void
list::print() {
	list_element *h = head;
	while (h != nullptr) {
		std::cout<<h->d<<"->";
		h = h->next;
	}
	std::cout<<"NULL"<<std::endl;
}


list::list(const list& lst) {
	if (lst.head == nullptr)
		head = cursor = nullptr;
	else {
		cursor = lst.head;
		list_element *prev = nullptr;
		list_element *h = new list_element(lst.head->d);
		head = h;
		prev = h;
		for (cursor = lst.head->next; cursor; ) {
			h = new list_element(cursor->d);
			prev->next = h;
			cursor = cursor->next;
			prev = h;
		}
		cursor = head;
	}
}


list::~list() {
	std::cout<<"Destructor called"<<std::endl;
	for (cursor = head; cursor; ) {
		cursor = head->next;
		delete head;
		head = cursor;
	}
}

int main() {
	list a, b;
	for (int i = 0; i < 10; i++)
		a.prepend(i*i);
	a.print();
	for (int i = 0; i < 10; i++)
		b.prepend(i*i*i);
	list c(b);
	b.print();
	c.print();
	return 0;
}