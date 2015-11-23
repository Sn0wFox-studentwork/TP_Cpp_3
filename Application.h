#pragma once
#include <map>

typedef uint16_t Uint16;

struct EtatNoeud	// Interne a Application ou pas ?
{
	int Occurences;
	bool EstIsole;
	EtatNoeud() : Occurences(0), EstIsole(true) { };
	EtatNoeud(const EtatNoeud& unEtat) : Occurences(unEtat.Occurences),
		EstIsole(unEtat.EstIsole) { };
	EtatNoeud& operator++() { ++Occurences; return *this; };	// prefix
	EtatNoeud operator++(int) {
		EtatNoeud res(*this);			// postfix
		++(*this);
		return res;
	};
};


typedef map<string, EtatNoeud> DicoNoeuds;
typedef map<string, int> DicoRequetes;

class Application
{
public:
	Application();
	virtual ~Application();
	void Run();

protected:
	void EcrireGraph();

	DicoNoeuds dicoNeuds;
	DicoRequetes dicoRequetes;
	Uint16 flags;
	
};

