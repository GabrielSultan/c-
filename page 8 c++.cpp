#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void displayArray(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertElement(int arr[], int &size, int element, int position) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert.\n";
        return;
    }
    if (position < 0 || position > size) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    cout << "Element inserted successfully.\n";
}

void deleteElement(int arr[], int &size, int position) {
    if (size == 0) {
        cout << "Array is empty. Nothing to delete.\n";
        return;
    }
    if (position < 0 || position >= size) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted successfully.\n";
}

void searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            cout << "Element found at index: " << i << "\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

void updateElement(int arr[], int size, int position, int newValue) {
    if (position < 0 || position >= size) {
        cout << "Invalid position.\n";
        return;
    }
    arr[position] = newValue;
    cout << "Element updated successfully.\n";
}

int main() {
    int arr[MAX_SIZE], size = 0;
    int choice, element, position;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Search Element\n";
        cout << "5. Update Element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position (0-based index): ";
                cin >> position;
                insertElement(arr, size, element, position);
                break;
            case 3:
                cout << "Enter position to delete (0-based index): ";
                cin >> position;
                deleteElement(arr, size, position);
                break;
            case 4:
                cout << "Enter element to search: ";
                cin >> element;
                searchElement(arr, size, element);
                break;
            case 5:
                cout << "Enter position to update (0-based index): ";
                cin >> position;
                cout << "Enter new value: ";
                cin >> element;
                updateElement(arr, size, position, element);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}
