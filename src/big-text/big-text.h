#ifndef BIG_TEXT_H_
#define BIG_TEXT_H_

#include <string>
#include <unordered_map>
#include <array>

using namespace std;

/** Typedef for maps used by BigText to determine how to print the ASCII art. */
typedef unordered_map<char, array<string, 5>> big_text_map;

/** Namespace containting all the default big_text_map. */
namespace big_text_maps {
  /** big_text_map only containing asii_letters. */
  extern big_text_map ascii_letters;
  /** big_text_map only containing digits. */
  extern big_text_map digits;
  /** big_text_map only containing punctuations. */
  extern big_text_map punctuation;
  /** big_text_map only containing whitepaces. */
  extern big_text_map whitespace;
  /** big_text_map containting all the characters of the previous maps. */
  extern big_text_map printables;
};

/** A class that prints strings in it's ascii-art form. */
class BigText {
  public:
    /** Constructor Function for BigText.
     *
     * @param str Initial string to print.
     * @param *map big_text_map to use.
     */
    BigText(string str = "", big_text_map *map = &big_text_maps::printables);
    /** Prints the stored string. */
    void print(void);
    /** Gets the text currently text stored in the class.
     *
     * @return The current stored text.
     * */
    string getText(void);
    /** Sets the text currently to print.
     *
     * @param str New string to set to.
     * @return *this (The object itself).
     */
    BigText& setText(string str);
    /** Gets the all characters that the class can printed.
     *
     * @return A string containing all supported chracters.
     * */
    string getSupportedCharacters(void);
    /** Sets the big_text_map to use when printing. */
    void setMap(big_text_map *map);
    /** Gets the big_text_map to currenlty being used when printing. */
    big_text_map& getMap(void);
  private:
    /** String currently stored. */
    string text;
    /** String containing all characters that can be printed. */
    string supported_characters;
    /** The map that conatins how each supported character is printed. */
    big_text_map *big_characters;
};

#endif 	// BIG-TEXT_H_
