#include <fstream>
#include <string>
#include "node.h"
#include "heap.h"
#include "huffman.h"

/* Private */

void huffman::compress() { /* O(n) */
    for (unsigned int i = 0; i < this->text.length(); ++i) {
        this->compressed += this->code[(int) this->text[i]];
    }
}

void huffman::generateCode(class Node *t, std::string binary) { /* O(n log n) */
    if (t->isLeaf() == true)
        this->code[(unsigned int)t->getCharacter()] = binary;
    else {
        if (t->getLeft() != 0)
            generateCode(t->getLeft(), binary + '0');
        if (t->getRight() != 0)
            generateCode(t->getRight(), binary + '1');
    }
}

void huffman::generateCode() { /* O(n log n) */
    if (this->tree->getLeft() != 0)
        generateCode(this->tree->getLeft(), "0");
    if (this->tree->getRight() != 0)
        generateCode(this->tree->getRight(), "1");
}

void huffman::generateTree() { /* O(n) */
    while (this->heap->getSize() > 1)
        this->heap->insert(new Node(this->heap->extract(), this->heap->extract()));

    this->tree = this->heap->extract();
}

void huffman::initFrequency() { /* O(n) */
    for (unsigned int i = 0; i < this->text.length(); ++i) {
        this->frequency[(unsigned int)this->text[i]]++;
    }
}

void huffman::initHeap() { /* O(1) */
    for (unsigned int i = 0; i < ASCII; ++i)
        if (frequency[i] > 0)
            this->heap->insert(new Node(i, frequency[i]));
}

/*
 * http://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
 * http://insanecoding.blogspot.com.br/2011/11/how-to-read-in-file-in-c.html
 */
void huffman::readFile(const char *filename) { /* O(1) */
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in) {
        in.seekg(0, std::ios::end);
        this->text.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&this->text[0], this->text.size());
        in.close();
        /*To remove extra \n at the end of the text*/
        if (this->text[this->text.length() - 1] == ENTER)
            this->text.erase(this->text.length() - 1, this->text.length());
    } else
        this->text = "The file could not be opened";
}

/* Public */

huffman::huffman(const char *filename) { /* O(1) */
    readFile(filename);

    for (unsigned int i = 0; i < ASCII; ++i)
        this->frequency[i] = 0;
    this->heap = new Heap(text.length());
}

huffman::~huffman() { /* O(n log n) */
    delete this->heap;
    this->tree->destroy();
    delete this->tree;
}

void huffman::encode() { /* O(n lg n) */
    initFrequency();
    initHeap();
    generateTree();
    generateCode();
    compress();
}

unsigned int huffman::getCompressedSize() { /* O(1) */
    return this->compressed.length();
}

std::string huffman::getCompressedText() { /* O(1) */
    return this->compressed;
}

float huffman::getCompressionRatio() { /* O(1) */
    return 100.0f - 100.0f * getCompressedSize() / getTextSize();
}

std::string huffman::getText() { /* O(1) */
    return this->text;
}

unsigned int huffman::getTextSize() { /* O(1) */
    return this->text.length() * BYTE;
}