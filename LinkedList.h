using namespace std;
typedef string ElementType;

struct Node
{
    ElementType data;
    Node * next;
};

class LinkedList
{
public:
    LinkedList(); // Create an empty LinkedList
    bool isEmpty(); // Return true if the LinkedList is empty, otherwise return false
    void InsertAtEnd(ElementType x); // Insert a value x at the end of the LinkedList
    void ReverseDisplay(); // Display the values in the LinkedList in reverse (do not reverse the actual LinkedList)
    void GetValueAt(int n); // Return the value at the provided location n
    void DeleteAll(ElementType x); // If value x is in the LinkedList, remove all instances of x
    void Display(string type); // Display the strings in the LinkedList based on the user's specification  (all of them, the even length ones, or the odd length ones).
    void Sort(); // Sort the LinkedList of strings based on length (shortest to longest)
    double Median(); // Compute and return the median string length for the strings in the LinkedList (must be sorted)
    void Shuffle(); // Shuffle the strings in the LinkedList around

private:
    Node * first; // Pointer to first Node of LinkedList
};