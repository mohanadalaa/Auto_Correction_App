# Spell Checker with Auto-Correction (C, Binary Search Tree)

A C-based spell checker that provides auto-correction suggestions for misspelled words using a **Binary Search Tree (BST)**. This project demonstrates efficient word search, suggestion generation, and basic data structure manipulation in C.

---

## Features

- Load a dictionary of words from `Dictionary.txt` into a BST.
- Check the spelling of each word in a user-input sentence.
- Provide auto-correction suggestions using:
  - The closest node in the BST.
  - In-order predecessor and successor nodes.
- Iterative search implementation for O(log N) efficiency.
- Displays dictionary statistics:
  - Total number of words (size of the BST).
  - Height of the BST.

---

## How It Works

1. **Dictionary Loading**
   - Reads words from `Dictionary.txt`.
   - Inserts each word into a BST.
   - Prints the size and height of the BST after loading.

2. **Spell Checking**
   - The user enters a sentence.
   - Each word is searched in the BST:
     - If the word exists, it is marked as correct.
     - If not, suggestions are provided using the predecessor and successor in the BST.

3. **Functions**
   - `getSize(Node* root)` – Calculates the total number of nodes in the BST.
   - `load(Node* root)` – Loads dictionary words into the BST.
   - `searchPreNode(Node* root, char* data)` – Searches iteratively for a word, returning the node if found or the closest node if not.
   - `input(char* str)` – Reads a sentence from the user safely.
   - `menu(Node* root)` – Main interactive loop for entering sentences and receiving suggestions.

---

## Usage

1. Clone the repository:

```bash
git clone https://github.com/mohanadalaa/Auto_Correction_App.git
