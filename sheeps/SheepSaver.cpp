#include "SheepSaver.hpp"
#include <fstream>
#include <iostream>
void SheepSaver::save(Matrix board) {
  std::vector<std::string> LETTERS = {"A", "B", "C", "D", "E", "F",
                                      "G", "H", "I", "J", "K", "L"};
  std::vector<std::string> PIECES = {
      "<td class=\"white\">&nbsp;</td>", "<td class=\"dark\">&nbsp;</td>",
      "<td class=\"dark\">&#128017;</td>", "<td class=\"dark\">&#128058;</td>"};
  std::ofstream myfile;
  myfile.open("board.html");
  std::string header =
      "<HTML>\n"
      "<meta http-equiv=\"Refresh\" content=\"5\">\n"
      "<!-- refresh every 5 seconds -->\n"
      "<HEAD>\n"
      "    <title>Sheep and Wold Example</title>\n"
      "    <style>\n"
      "    table { border-spacing: 1px;}\n"
      "    td { text-align:center ; padding: 15px; font-size: 36px;}\n"
      "    td.dark { background: burlywood; min-width: 45px; min-height: "
      "40px;}\n"
      "    td.white {background: beige ;}\n"
      "    h2 { padding-left: 220px; }"
      "    </style>"
      "</HEAD>"
      "<BODY>"
      "<h2>Sheep and Wolf Example</h2>\n"
      "<table>\n";
  std::string footer = "</table>\n</BODY>\n</HTML>\n";
  myfile << header;
  // do the implementation of writing the board
  int x = 0;
  int y = 0;
  int rows = board.size();
  int cols = board.size();
  for (int i = 0; i < rows; i++) {
    // first cell line numbers
    myfile << "<tr>\n";
    myfile << "<td>" << rows - i << "</td>";
    // now the pieces or empty squares
    for (int j = 0; j < cols; j++) {
      myfile << PIECES[board[i][j]];
    }
    myfile << "</tr>\n";
  }
  // LETTERS at the bottom row
  myfile << "<tr>\n<td>&nbsp;</td>";
  for (int j = 0; j < cols; j++) {
    myfile << "<td>" << LETTERS[j] << "</td>";
  }
  myfile << "</tr>\n
      myfile
         << footer;
  myfile.close();
}
