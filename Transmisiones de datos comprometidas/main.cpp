// =========================================================
// File: main.cpp
// Author: Jesús Jiménez Aguilar
// Date: 21 de enero de 2022
// =========================================================

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 3003

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// PARTE 1 ACTIVIDAD INTEGRADORA

// La solución debe determinar si existen algunos de los códigos maliciosos en
// ambos archivos de transmisión. En caso de que se encuentre alguno de los
// códigos maliciosos, se desplegrará true, seguido de la posición en el archivo
// de transmisión donde inicia ese código malicioso.

// Complejidad O(n)
//-------------ALGORITMO LOSNGEST PROPER PREFIX -----------------

vector<int> longestProperPrefix(string patron) {
  int n = patron.length();
  // Longest proper prefix también cuenta con función de sufijo
  vector<int> longestProperPrefixVec(n, 0);
  int j = 0, i = 1;
  while (i < n) {
    // Si hay patrones que coinciden
    if (patron[i] == patron[j]) {
      longestProperPrefixVec[i] = j + 1;
      i++;
      j++;
    } else {
      // Si no hay patrones que coincidan
      if (j == 0) {
        //
        longestProperPrefixVec[i] = 0;
        i++;
      } else {
        // Regresa un índice
        j = longestProperPrefixVec[j - 1];
      }
    }
  }
  return longestProperPrefixVec;
}

// ------ ALGORITMO Knuth-Morris-Pratt -----RECONOCER PATRONES
// Complejidad: O(n)
pair<int, vector<int>> kmp(string &transmission, string code) {
  // Número de veces que codigo es encontrado
  int found = 0;
  // Indices de donde el codigo es encontrado
  vector<int> positionsMatching;
  vector<int> longestProperPrefixVec = longestProperPrefix(code);
  int j = 0, i = 0;
  int t = transmission.length();
  int p = code.length();

  while (i < t) {
    if (transmission[i] == code[j]) {
      i++;
      j++;
      if (j == p) {
        positionsMatching.push_back(i - p);
        j = longestProperPrefixVec[j - 1];
        found++;
      }
    } else {
      if (j == 0) {
        i++;
      } else {
        j = longestProperPrefixVec[j - 1];
      }
    }
  }

  return {found, positionsMatching};
}

// Complejidad: O(n*m)
void codeFoundOutput(vector<string> &transmisiones,
                     vector<string> &codigosMaliciosos) {
  for (int i = 0; i < codigosMaliciosos.size(); i++) {
    for (int j = 0; j < transmisiones.size(); j++) {
      pair<int, vector<int>> foundCodes =
          kmp(transmisiones[j], codigosMaliciosos[i]);
      cout << "mcode" << i + 1 << ".txt - ";
      if (foundCodes.first > 0) {
        cout << "true, start at position ";
        for (int k = 0; k < foundCodes.second.size(); k++) {
          cout << foundCodes.second[k] << " ";
        }
        cout << endl;
      } else {
        cout << "false" << endl;
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// PARTE 2 ACTIVIDAD INTEGRADORA

// La solución debe considerar que pueden existe códigos maliciosos desconocidos
// que debemos buscar. Si la solución encuentra un código malicioso de este
// estilo, debera desplegar en una sola línea en que posición inicia y termina
// el código "espejeado" más largo que ha encontrado. Puedes asumir que siempre
// encontrarás este tipo de código.

// Complejidad: O(n)
//------------------------------ENCONTRAR CÓDIGO CON MALWARE
//-----------------------------------------------
// Utilizamos manacher para identificar fragmentos de código espejeados

pair<string, pair<int, int>> manacher(string text) {
  // Nuevo string auxiliar
  string T = "";
  int n = text.length();
  for (int i = 0; i < n; i++) {
    // Se agrega "|" entre cada caracter
    T += "|";
    T += text[i];
  }
  T += "|";
  // Nueva longitud
  n = T.length();
  vector<int> L(n);
  L[0] = 0;
  L[1] = 1;
  int maxLong = 0, maxCenter = 0;
  bool exp;
  for (int c = 1, li = 0, ri = 2; ri < n; ri++) {
    li = c - (ri - c);
    exp = false;
    if (c - maxLong <= ri && ri >= c + maxLong) {
      if (L[li] < (c + L[c] - ri)) {
        L[ri] = L[li];
      } else if (L[li] == (c + L[c]) - ri && (c + L[c]) == 2 * n) {
        L[ri] = L[li];
      } else if (L[li] == (c + L[c]) - ri && (c + L[c]) < 2 * n) {
        L[ri] = L[li];
        exp = true;
      } else if (L[li] > (c + L[c]) - ri && (c + L[c]) < 2 * n) {
        L[ri] = (c + L[c]) - ri;
        exp = true;
      }
    } else {
      L[ri] = 0;
      exp = true;
    }
    if (exp) {
      while ((ri + L[ri] < n) && (ri - L[ri] > 0) &&
             (T[ri - L[ri] - 1] == T[ri + L[ri] + 1])) {
        L[ri]++;
      }
    }
    c = ri;
    if (L[ri] > maxLong) {
      maxLong = L[ri];
      maxCenter = ri;
    }
  }
  int start = (maxCenter - maxLong) / 2;
  int end = start + maxLong - 1;
  string exit = "";
  for (int i = start; i < (start + maxLong); i++) {
    exit += text[i];
  }

  // Regresa palindromo, posicion inicial y posicion final.
  return {exit, {start, end}};
}

// Complejidad: O(n)
//---------------------ACUMULAR CÓDIGO MALICIOSO -------------
// Malware se encuentra a manera de palindromes

void findPalindrome(vector<string> &transmisiones) {
  vector<pair<string, pair<int, int>>> palindromes;
  for (int i = 0; i < transmisiones.size(); i++) {
    palindromes.push_back(manacher(transmisiones[i]));
  }

  for (int i = 0; i < transmisiones.size(); i++) {
    cout << endl << "transmission" << i + 1 << ".txt:";
    cout << endl
         << "mirrored code found, start at " << palindromes[i].second.first
         << ", ended at " << palindromes[i].second.second + 1 << endl;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// PARTE 3 ACTIVIDAD INTEGRADORA

// La solución debe determinar que tan similares son los archivos de
// transmisión, desplegando la longitud de la subsecuencia común más larga entre
// ambos archivos.

// Complejidad: O(n*m)
//--------------------------ENCONTRAR EL Longest Common Substring
//--------------------------------------

pair<string, pair<int, int>> LCSS(string st1, string st2) {
  vector<vector<int>> suffix(st1.length() + 1, vector<int>(st2.length() + 1));
  int lengthLCSS = 0;
  int end = -1;

  for (int i = 0; i <= st1.length(); i++) {
    for (int j = 0; j <= st2.length(); j++) {
      if (i == 0 || j == 0) {
        suffix[i][j] = 0;
      } else if (st1[i - 1] == st2[j - 1]) {
        suffix[i][j] = suffix[i - 1][j - 1] + 1;
        if (lengthLCSS < suffix[i][j]) {
          lengthLCSS = suffix[i][j];
          end = i;
        }
      } else {
        suffix[i][j] = 0;
      }
    }
  }

  return {st1.substr(end - lengthLCSS, lengthLCSS),
          {end - lengthLCSS, end - 1}};
}

// Complejidad: O(1)
void getLongestSubstring(vector<string> transmisiones) {
  pair<string, pair<int, int>> LCSSData =
      LCSS(transmisiones[0], transmisiones[1]);
  cout << endl
       << "the longest common substring between transmission1.txt and "
          "transmission2.txt is "
       << LCSSData.second.second - LCSSData.second.first + 1
       << " characters long" << endl;
}

/* ----------------------------------------------------------------
   ---------------------------------------------------------------- */

int main() {
  // Variables para transición y revisión de cada caso de prueba
  string mcode1, mcode2, mcode3, t1, t2;
  vector<string> codigosMaliciosos;
  vector<string> transmisiones;
  vector<string> busquedaT1;
  vector<string> busquedaT2;

  // Leer archivos
  ifstream archivoCodigoMalicioso1("mcode1.txt");
  ifstream archivoCodigoMalicioso2("mcode2.txt");
  ifstream archivoCodigoMalicioso3("mcode3.txt");
  ifstream archivoTransmission1("transmission1.txt");
  ifstream archivoTransmission2("transmission2.txt");

  // Leer y guardar codigos maliciosos en el vector
  getline(archivoCodigoMalicioso1, mcode1);
  getline(archivoCodigoMalicioso2, mcode2);
  getline(archivoCodigoMalicioso3, mcode3);
  codigosMaliciosos.push_back(mcode1);
  codigosMaliciosos.push_back(mcode2);
  codigosMaliciosos.push_back(mcode3);

  // Leer y guardar transmisiones en el vector
  getline(archivoTransmission1, t1);
  getline(archivoTransmission2, t2);
  transmisiones.push_back(t1);
  transmisiones.push_back(t2);
  busquedaT1.push_back(t1);
  busquedaT2.push_back(t2);

  cout << "transmission1.txt:" << endl;
  codeFoundOutput(busquedaT1, codigosMaliciosos);
  cout << endl;
  cout << "transmission2.txt:" << endl;
  codeFoundOutput(busquedaT2, codigosMaliciosos);

  findPalindrome(transmisiones);

  getLongestSubstring(transmisiones);

  return 0;
}