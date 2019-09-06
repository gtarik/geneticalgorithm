# Genetic Algorithm

A simple genetic algorithm example (C++), which solves the Shakespearean monkey problem.

## Getting Started

The best way to understand the genetic algorithm is to work through a simple problem

## Example walkthrough

Let’s go through the Shakespearean monkey problem, and possible ways to solve this problem.

### Shakespearean monkey problem
Let’s assume we give a typing machine to a monkey. Let it be a simplified typing machine with only 27 letters of the English alphabet.

If we now let the monkey type on the typing machine for an infinite amount of time, it will eventually type all the works of Shakespeare.

Now let’s say the monkey was supposed to write just the sentence “To be or not to be that is the question”. In this case the monkey has a chance to write the whole sentence correctly 1 to 27^39 (since the sentence has 39 letters).

With the impossible assumption, that the monkey types one million characters per second, it would need about 9.719.096.182.010.563.073.125.591.133.903.305.625.605.017 years. Note that the age of the universe is estimated to be 13.750.000.000 years.

### The genetic algorithm approach
With the genetic algorithm we simulate nature’s principle “survival of the fittest”. We first generate a population of members, with randomized genetic material. In this case, a member is a string with 39 randomized characters, each character represents the DNA of the specific member. Now we evaluate the generated members and compare them with the target string “to be or not to be that is the question”. 
The strings that have more correct characters, have a higher fitness value, therefore a higher chance to pass their DNA to the next generation. 
After calculating the fitness values, we do a cross over between the members of the population. In result we receive a new generation with new members, and eventually come closer to the target string.
To add more variation to the population, we define a mutation rate, so for a given chance a member can mutate to a new string of characters.
After a certain number of generations our population evolves to the target string.
## Authors

* **Tarik Gruhonjic**  - [Tarik Gruhonjic](https://github.com/gtarik)

## Acknowledgments

* Hat tip to Daniel Shiffman
