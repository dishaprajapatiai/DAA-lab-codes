#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    
    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Traverse the Huffman Tree and store codes in a map
void generateCodes(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root) return;
    
    // If this is a leaf node (contains character)
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    
    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

// Encode a word using the Huffman codes
string encodeWord(const string &word, const unordered_map<char, string> &huffmanCode) {
    string encoded = "";
    for (char c : word) {
        char lowerC = tolower(c);  // just in case
        if (huffmanCode.find(lowerC) != huffmanCode.end()) {
            encoded += huffmanCode.at(lowerC);
        } else {
            cout << "Warning: character '" << c << "' not found in Huffman codes." << endl;
        }
    }
    return encoded;
}

int main() {
    // Given frequencies
    unordered_map<char, int> frequencies = {
        {'a', 26},
        {'e', 18},
        {'o', 20},
        {'s', 14},
        {'t', 10},
        {'n', 12}
    };
    
    // Create a priority queue to store live nodes of Huffman tree
    priority_queue<Node*, vector<Node*>, Compare> pq;
    
    // Create leaf nodes for each character and push into pq
    for (auto pair : frequencies) {
        pq.push(new Node(pair.first, pair.second));
    }
    
    // Build Huffman tree
    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    
    Node* root = pq.top();
    
    // Generate Huffman codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);
    
    // Print the Huffman codes
    cout << "Huffman Codes for the characters:" << endl;
    for (auto pair : frequencies) {
        cout << pair.first << ": " << huffmanCode[pair.first] << endl;
    }
    
    // Words to encode
    vector<string> words = {"stone", "tea", "sea"};
    
    cout << "\nEncoded bits for the words:" << endl;
    for (auto &word : words) {
        cout << word << ": " << encodeWord(word, huffmanCode) << endl;
    }
    
    return 0;
}
