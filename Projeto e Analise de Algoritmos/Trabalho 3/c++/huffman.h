#ifndef HUFFMAN_H
#define	HUFFMAN_H

#include <string>
#define ASCII 128
#define BYTE 8
#define ENTER 10

class huffman {
private:
    class Node *tree;
    class Heap *heap;
    unsigned int frequency[ASCII];
    std::string text, compressed, code[ASCII];
    void compress();
    void generateCode(class Node *t, std::string binary);
    void generateCode();
    void generateTree();
    void initFrequency();
    void initHeap();
    void readFile(const char *filename);
public:
    huffman(const char *filename);
    ~huffman();
    void encode();
    unsigned int getCompressedSize();
    std::string getCompressedText();
    float getCompressionRatio();
    std::string getText();
    unsigned int getTextSize();    
};

#endif	/* HUFFMAN_H */