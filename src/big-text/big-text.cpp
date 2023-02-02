/** @file */
#include "big-text.h"

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

BigText::BigText(string str, big_text_map *map): big_characters(map), text(str) {
  // Adding supported_characters
  for(auto it: *this->big_characters) {
    this->supported_characters += it.first;
  }
}

void BigText::print(ostream &stream) {
  // Looping over 5 lines
  for(int i = 0; i < 5; i ++) {
    // Looping over the all characters
    for(int j = 0; j < text.length(); j++) {
      char current_char = text[j];

      if (big_characters->count(current_char) == 0) {
        stream << "      ";
        continue;
      }
      // Printing Characters
      stream << big_characters->at(current_char)[i] << " ";
    }

    // Printing New Line
    stream << endl;
  }
}

string BigText::getText() {
  return this->text;
}

BigText& BigText::setText(string str) {
  this->text = str;
  return *this;
}

string BigText::getSupportedCharacters(void) {
  return supported_characters;
}

void BigText::setMap(big_text_map *map) {
  this->big_characters = map;

  // Resetting supported_characters
  this->supported_characters.clear();
  // Updating supported_characters
  for(auto it: *this->big_characters) {
    this->supported_characters += it.first;
  }
}

big_text_map& BigText::getMap() {
  return *this->big_characters;
}

/** Default big_text_map definitions
 * */

/** Merges two unordered_maps together.
 *
 * All the keys and it's corresponding values in map2 will be
 * copied over to map1. If the key is already in map1, the key will
 * be ignored and the value from map1 will be used.
 *
 * @param map1 First unordered_map to be merged
 * @param map2 Second unordered_map to be merged
 *
 * @return The resultant merged unordered_map.
 * */
template <class Key, class Tp>
static unordered_map<Key, Tp> mergeMaps(unordered_map<Key, Tp> map1,
                                        unordered_map<Key, Tp> map2) {
    map1.merge(map2);
    return map1;
}

/** Merges 3 or more unordered_maps together.
 *
 * All the keys and it's corresponding values in map2 and args will be
 * copied over to map1. If the key is already in map1, the key will
 * be ignored and the value from map1 will be used.
 *
 * @param map1 First unordered_map to be merged
 * @param map2 Second unordered_map to be merged
 * @param args Other additional maps to be merged together.
 *
 * @return The resultant merged unordered_map.
 * */
template <class Key, class Tp, class... Args>
static unordered_map<Key, Tp> mergeMaps(unordered_map<Key, Tp> map1,
                                        unordered_map<Key, Tp> map2, Args... args) {
    map1.merge(map2);
    return mergeMaps(map1, args...);
}

// Letters
big_text_map big_text_maps::ascii_letters = {
  // A
  {'A',
   {" *** ",
    "*   *",
    "*****",
    "*   *",
    "*   *"}},
  // B
  {'B',
   {"**** ",
    "*   *",
    "**** ",
    "*   *",
    "**** "}},
  // C
  {'C',
   {"  ***",
    " *   ",
    "*    ",
    " *   ",
    "  ***"}},
  // D
  {'D',
   {"***  ",
    "*  * ",
    "*   *",
    "*  * ",
    "***  "}},
  // E
  {'E',
   {"*****",
    "*    ",
    "**** ",
    "*    ",
    "*****"}},
  // F
  {'F',
   {"*****",
    "*    ",
    "**** ",
    "*    ",
    "*    "}},
  // G
  {'G',
   {" ****",
    "*    ",
    "* ***",
    "*   *",
    " ****"}},
  // H
  {'H',
   {"*   *",
    "*   *",
    "*****",
    "*   *",
    "*   *"}},
  // I
  {'I',
   {"*****",
    "  *  ",
    "  *  ",
    "  *  ",
    "*****"}},
  // J
  {'J',
   {"*****",
    "   * ",
    "   * ",
    "*  * ",
    " **  "}},
  // K
  {'K',
   {"*  **",
    "* *  ",
    "**   ",
    "* *  ",
    "*  **"}},
  // L
  {'L',
   {"*    ",
    "*    ",
    "*    ",
    "*    ",
    "*****"}},
  // M
  {'M',
   {"*   *",
    "** **",
    "* * *",
    "*   *",
    "*   *"}},
  // N
  {'N',
   {"*   *",
    "**  *",
    "* * *",
    "*  **",
    "*   *"}},
  // O
  {'O',
   {" *** ",
    "*   *",
    "*   *",
    "*   *",
    " *** "}},
  // P
  {'P',
   {"***  ",
    "*  * ",
    "***  ",
    "*    ",
    "*    "}},
  // Q
  {'Q',
   {" *** ",
    "*   *",
    "*   *",
    " *** ",
    "    *"}},
  // R
  {'R',
   {"**** ",
    "*   *",
    "**** ",
    "*  * ",
    "*   *"}},
  // S
  {'S',
   {" ****",
    "*    ",
    " *** ",
    "    *",
    "**** "}},
  // T
  {'T',
   {"*****",
    "  *  ",
    "  *  ",
    "  *  ",
    "  *  "}},
  // U
  {'U',
   {"*   *",
    "*   *",
    "*   *",
    "*   *",
    " *** "}},
  // V
  {'V',
   {"*   *",
    "*   *",
    "*   *",
    " * * ",
    "  *  "}},
  // W
  {'W',
   {"*   *",
    "*   *",
    "* * *",
    "* * *",
    " * * "}},
  // X
  {'X',
   {"*   *",
    " * * ",
    "  *  ",
    " * * ",
    "*   *"}},
  // Y
  {'Y',
   {"*   *",
    " * * ",
    "  *  ",
    "  *  ",
    "  *  "}},
  // Z
  {'Z',
   {"*****",
    "   * ",
    "  *  ",
    " *   ",
    "*****"}}
};
// Digits
big_text_map big_text_maps::digits = {
  // 0
  {'0',
   {"*****",
    "*   *",
    "*   *",
    "*   *",
    "*****"}},
  // 1
  {'1',
   {"    *",
    "    *",
    "    *",
    "    *",
    "    *"}},
  // 2
  {'2',
   {"*****",
    "    *",
    "*****",
    "*    ",
    "*****"}},
  // 3
  {'3',
   {"*****",
    "    *",
    "*****",
    "    *",
    "*****"}},
  // 4
  {'4',
   {"*   *",
    "*   *",
    "*****",
    "    *",
    "    *"}},
  // 5
  {'5',
   {"*****",
    "*    ",
    "*****",
    "    *",
    "*****"}},
  // 6
  {'6',
   {"*****",
    "*    ",
    "*****",
    "*   *",
    "*****"}},
  // 7
  {'7',
   {"*****",
    "    *",
    "    *",
    "    *",
    "    *"}},
  // 8
  {'8',
   {"*****",
    "*   *",
    "*****",
    "*   *",
    "*****"}},
  // 9
  {'9',
   {"*****",
    "*   *",
    "*****",
    "    *",
    "*****"}},
};
// Punctuations
big_text_map big_text_maps::punctuation = {
  // !
  {'!',
   {"  *  ",
    "  *  ",
    "  *  ",
    "     ",
    "  *  "}},
  // @
  {'@',
   {"*****",
    "* ***",
    "* ***",
    "*    ",
    "*****"}},
  // #
  {'#',
   {" * * ",
    "*****",
    " * * ",
    "*****",
    " * * "}},
  // $
  {'$',
   {" ****",
    "* *  ",
    " *** ",
    "  * *",
    "**** "}},
  // %
  {'%',
   {"*   *",
    "   * ",
    "  *  ",
    " *   ",
    "*   *"}},
  // ^
  {'^',
   {"  *  ",
    " * * ",
    "*   *",
    "     ",
    "     "}},
  // &
  {'&',
   {" *** ",
    " *   ",
    "* * *",
    "*  * ",
    "*** *"}},
  // *
  {'*',
   {"*   *",
    " * * ",
    "*****",
    " * * ",
    "*   *"}},
  // (
  {'(',
   {"  *  ",
    " *   ",
    "*    ",
    " *   ",
    "  *  "}},
  // )
  {')',
   {"  *  ",
    "   * ",
    "    *",
    "   * ",
    "  *  "}},
// [
  {'[',
   {"***  ",
    "*    ",
    "*    ",
    "*    ",
    "***  "}},
  // ]
  {']',
   {"  ***",
    "    *",
    "    *",
    "    *",
    "  ***"}},
  // ;
  {';',
   {" **  ",
    " **  ",
    "     ",
    " **  ",
    "**   "}},
  // '
  {'\'',
   {"*    ",
    "*    ",
    "     ",
    "     ",
    "     "}},
// ,
  {',',
   {"     ",
    "**   ",
    "**   ",
    " *   ",
    "*    "}},
  // .
  {'.',
   {"     ",
    "     ",
    "     ",
    "**   ",
    "**   "}},
  // ?
  {'?',
   {"**** ",
    "    *",
    "  ** ",
    "     ",
    "  *  "}}
};
// Whitespace
big_text_map big_text_maps::whitespace = {
  // White Space
  {' ',
   {"     ",
    "     ",
    "     ",
    "     ",
    "     "}}
};
// Everything
big_text_map big_text_maps::printables = mergeMaps(ascii_letters, digits, punctuation, whitespace);
