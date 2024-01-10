#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void Merge(int arr1[], int size1, int arr2[], int size2, int mergedArr[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        }
        else {
            mergedArr[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }
    // Sort the merged array
    sort(mergedArr, mergedArr + size1 + size2);
}

void Common(int arr1[], int size1, int arr2[], int size2) {
    cout << "Common elements: ";
    sort(arr1, arr1 + size1);
    sort(arr2, arr2 + size2);
    for (int i = 0; i < size1; i++) {
        if (binary_search(arr2, arr2 + size2, arr1[i])) {
            cout << arr1[i] << " ";
        }
    }
    cout << endl;
}

bool isPalindrome(string sentence) {
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
    sentence.erase(remove_if(sentence.begin(), sentence.end(), ::isspace), sentence.end());
    sentence.erase(remove_if(sentence.begin(), sentence.end(), ::ispunct), sentence.end());

    int start = 0;
    int end = sentence.length() - 1;
    while (start < end) {
        if (sentence[start] != sentence[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void printArray(int arr[], int size) {
    cout << "Merged Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Create arrays and prompt user for input
    int arr1[5];
    int arr2[7];
    cout << "Enter 5 integers for the first array: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr1[i];
    }
    cout << "Enter 7 integers for the second array: ";
    for (int i = 0; i < 7; i++) {
        cin >> arr2[i];
    }

    // Merge the arrays
    int mergedArr[12];
    Merge(arr1, 5, arr2, 7, mergedArr);

    // Print merged array
    printArray(mergedArr, 12);

    // Find common elements
    Common(arr1, 5, arr2, 7);

    // Prompt user for input sentence
    string sentence;
    cout << "Enter a sentence: ";
    cin.ignore();
    getline(cin, sentence);

    // Check if sentence is a palindrome
    bool isPalin = isPalindrome(sentence);
    if (isPalin) {
        cout << "The sentence is a palindrome." << endl;
    }
    else {
        cout << "The sentence is not a palindrome." << endl;
    }

    return 0;
}
