#include <iostream>
using namespace std;
class Dictionary {
private:
    const int DICTIONARY_LIMIT = 500;
    int count = 0;
    Pair* pairs;

    bool isFullDisctionary()
    {
        return this->count < 500;
    }

    bool isEqualTwoStrings(const char* word1, const char* word2)
    {
        // < 0 the first character that does not match has a lower value in ptr1 than in ptr2
        // 0	the contents of both strings are equal
        // >0 the first character that does not match has a greater value in ptr1 than in ptr2
        if (strcmp(word1, word2) == 0)
            return true;

        return false;
    }

    void movePairs(Pair* pairs, int count) {
        for (size_t i = 0; i < count-1; i++)
        {
            if (pairs[i].word == nullptr && pairs[i].interpretation == nullptr)
            {
                for (size_t j = i; j < count - 1; j++)
                {
                    pairs[j] = pairs[j + 1];
                }
                return;
            }
        }
    }
public:
    void print() const {
        cout << "Content of my dictionary is :" << endl;
        for (size_t i = 0; i < count; i++)
        {
            cout << pairs[i].word << " : " << pairs[i].interpretation << endl;
        }
    }

    void addPair(const Pair& pair) {
        if (isFullDisctionary())
        {
            cout << "Dictionary is full" << endl;
        }
        else {
            this->pairs[this->count] = pair;
            this->count++;
        }
    }

    void addPair(char word[], char interpretation[]) {
        if (isFullDisctionary())
        {
            cout << "Dictionary is full" << endl;
        }
        else {
            Pair currentPair;
            currentPair.word = word;
            currentPair.interpretation = interpretation;

            this->pairs[this->count] = currentPair;
            this->count++;
        }
    }

    void removePair(const char word[])
    {
        for (size_t i = 0; i < count; i++)
        {
            if (isEqualTwoStrings(pairs[i].word, word))
            {
                Pair nullPair;
                nullPair.word = nullptr;
                nullPair.interpretation = nullptr;
                pairs[i] = nullPair;

                movePairs(this->pairs, this->count);
                this->count--;           
            }
        }
    }

    void searchInterpretation(const char word[]) {
        for (size_t i = 0; i < count; i++)
        {
            if (isEqualTwoStrings(pairs[i].word, word))
            {
                cout << "Interpretation for this word is: " << pairs[i].interpretation << endl;
                return;
            }
        }

        cout << "Not founded this word " << endl;
    }
};
struct Pair
{
private:
    const int LENGTH_OF_WORD = 100;
    const int LENGTH_OF_DESCRIPTION = 500;
public:
    char* word;
    char* interpretation;
    
    Pair& operator = (const Pair& pair) {
        if (this != &pair)
        {
            delete[] word;
            this->word = new char[strlen(pair.word) + 1];
            strcpy(this->word, pair.word);

            delete[] interpretation;
            this->interpretation = new char[strlen(pair.interpretation) + 1];
            strcpy(this->interpretation, pair.interpretation);
        }
    }
};
int main()
{
    std::cout << "Hello World!\n";
}
