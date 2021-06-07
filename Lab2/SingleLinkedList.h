#include <string>

class SinglyLinkedOrderedList
{
private:
		struct Node
		{
				int item_;
				Node* next_;

				Node(int item, Node* next = nullptr) : item_(item), next_(next) { }
				Node() = default;
		};

		Node* head_;
		Node* head() const { return head_; }

		void insertNode(Node* x);
		Node* searchNode(int item);

public:
		friend std::ostream& operator<< (std::ostream& os, const SinglyLinkedOrderedList& list);

		void insertItem(int item);
		bool searchItem(int item);
		void deleteNode(int name);

		SinglyLinkedOrderedList() : head_(nullptr) {}

		void insertList(const SinglyLinkedOrderedList& list);
		friend SinglyLinkedOrderedList operator+ (const SinglyLinkedOrderedList& list1, const SinglyLinkedOrderedList list2);

		void subtractList(const SinglyLinkedOrderedList& list);
		friend SinglyLinkedOrderedList operator- (const SinglyLinkedOrderedList& list1, const SinglyLinkedOrderedList list2);

		int getCount(Node* head);

		SinglyLinkedOrderedList intersectionList(const SinglyLinkedOrderedList& that);
		friend SinglyLinkedOrderedList operator* (const SinglyLinkedOrderedList& list1, const SinglyLinkedOrderedList list2);

		bool search(Node* head, int x);
};