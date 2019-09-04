#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

//creating the population
//each member of the population consists of a DNA (a string) and a fitness value
struct Member {
	std::string DNA;
	int Fitness;
};

struct Population {
	//creating a population of N Members
	std::vector<Member> Members = std::vector<Member>(1000);
};


int main() {
	//We are searching for the target string
	std::string targetDNA = "To be or not to be that is the question";

	//when the stoppage criteria is met, the loop will terminate
	bool StoppageCriteria = false;

	//the mutation rate defines at which rate a mutation will occur
	// 1000 = 100%  and 1 = .01% etc
	int MutationRate = 20;

	//time seed for random numbers
	srand(time(NULL));

	//Create a population and fill the strings with random character combinations
	Population Pop;

	for (int i = 0; i < Pop.Members.size(); i++) {
		Pop.Members.at(i).DNA.resize(targetDNA.size());
		for (int j = 0; j < targetDNA.size(); j++) { Pop.Members.at(i).DNA.at(j) = (unsigned char)rand() % 96 + 32; }
	}

	//variable for tracking the generation number
	int Generation = 0;

	//this loop will continue untill the string has evolved to the target string.
	while (!StoppageCriteria) {
		Generation++;

		//recalculate fitness for each member of the population, and check if the stoppage criteria has been met
		for (int i = 0; i < Pop.Members.size(); i++) {
			Pop.Members.at(i).Fitness = 0;
			for (int j = 0; j < Pop.Members.at(i).DNA.size(); j++) { if (Pop.Members.at(i).DNA.at(j) == targetDNA.at(j)) { Pop.Members.at(i).Fitness += 10; } }
			if (Pop.Members.at(i).Fitness == targetDNA.size() * 10) StoppageCriteria = true;
		}

		//sorting the population by the fitness value
		std::sort(Pop.Members.begin(), Pop.Members.end(), [](Member const &a, Member const &b) {return a.Fitness > b.Fitness; });

		//pick N amount of highest fitness members to mate, in this case 2 are being used
		std::vector<Member> Parents{ Pop.Members.at(0), Pop.Members.at(1)/*, Pop.Members.at(2), Pop.Members.at(3), Pop.Members.at(4), Pop.Members.at(5)*/ };

		//genetic operator => permutation of the genes 
		for (int i = 0; i < Pop.Members.size(); i++) {

			for (int j = 0; j < Pop.Members.at(i).DNA.size(); j++) {

				int TempSelection = rand() % Parents.size();
				Pop.Members.at(i).DNA.at(j) = Parents.at(TempSelection).DNA.at(j);

				//random mutation to expand the gene pool of a generation
				if (rand() % 1000 < MutationRate) { Pop.Members.at(i).DNA.at(j) = (unsigned char)rand() % 96 + 32; }
			}
		}

		//print the best member of the population
		std::cout << "Generation : " << Generation << " Number of correct characters " << Parents.at(0).Fitness / 10 << " / " << targetDNA.size() << " With DNA : " << Parents.at(0).DNA.c_str() << std::endl;
	}

	std::cout << "Generation " << Generation << " Evolved to the full sequence" << std::endl;
	return 0;
}
