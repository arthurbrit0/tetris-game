#pragma once
#include <raylib.h>
#include <vector>

extern const Color darkGrey; // definindo as cores que serão implementadas no arquivo principal
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;

std::vector<Color> GetCellColors(); // definindo a função que retornará um vetor do tipo Cores no arquivo principal