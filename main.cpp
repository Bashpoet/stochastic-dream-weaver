#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <sstream>
#include <map>
#include <Eigen/Dense> // Include Eigen library for linear algebra

// --- Helper Functions ---

// Function to generate a random double within a range
double randomDouble(double min, double max, std::mt19937& gen) {
    std::uniform_real_distribution<> dist(min, max);
    return dist(gen);
}

// Enhanced describeConcept function
std::string describeConcept(const std::string& concept, double value, std::mt19937& gen) {
    std::stringstream ss;
    if (concept == "fractal") {
        ss << "fractal blooms, each iteration revealing " << (value > 0.5 ? "more vibrant detail" : "a deeper, swirling chaos");
    } else if (concept == "exponential") {
        ss << "an exponential surge, the intensity growing " << (value > 0.5 ? "to an ecstatic peak" : "towards an overwhelming oblivion");
    } else if (concept == "chaotic") {
        ss << "a chaotic dance, where " << (value > 0.5 ? "patterns briefly emerge" : "disorder reigns supreme");
    } else if (concept == "periodic") {
        ss << "periodic waves, cresting and falling with the rhythm of " << (value > 0.5 ? "a fevered pulse" : "a slowly fading heartbeat");
    } else if (concept == "singular") {
        ss << "singularities, points of infinite density where " << (value > 0.5 ? "reality itself fractures" : "consciousness dissolves");
    } else if (concept == "gaussian") {
        ss << "a Gaussian blur, where clarity peaks at the center and fades into " << (value > 0.5 ? "a hazy, dreamlike periphery" : "an indistinct, ethereal mist");
    } else if (concept == "poisson") {
        ss << "a Poisson distribution of phantasms, appearing with a seemingly random, yet statistically predictable, frequency, like " << (value > 0.5 ? "sparks from a dying ember" : "glimmers in the deepest ocean");
    } else if (concept == "eigenvector") {
        // Use Eigen to generate a random covariance matrix and find its eigenvectors
        Eigen::MatrixXd cov(3, 3);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cov(i, j) = randomDouble(-1, 1, gen);
            }
        }
        cov = cov * cov.transpose(); // Ensure positive semi-definite
        Eigen::EigenSolver<Eigen::MatrixXd> es(cov);
        Eigen::VectorXcd evec = es.eigenvectors().col(0); // Take the first eigenvector (complex)

        ss << "eigenvectors of a shimmering covariance matrix, principal components whispering forgotten stanzas from the stochastic depths of Xanadu.  The dominant eigenvector, ("
           << evec(0).real() << ", " << evec(1).real() << ", " << evec(2).real() << "), guides the dream's trajectory.";

    } else if (concept == "homotopy") {
      int numLoops = static_cast<int>(randomDouble(1,5, gen));
        ss << "homotopy classes winding through the labyrinth of cognition, where each of the "<< numLoops <<" loops is a recursion into forgotten poetry, a topological knot in the fabric of consciousness.";
    }
    return ss.str();
}
//Markov Chain Transition Probability Matrix
std::map<std::string, std::map<std::string, double>> createTransitionMatrix(std::mt19937& gen)
{
    std::vector<std::string> concepts = {"fractal", "chaotic", "periodic", "singular", "gaussian", "poisson", "eigenvector", "homotopy"};
    std::map<std::string, std::map<std::string, double>> transitionMatrix;

     for (const auto& concept1 : concepts) {
        std::map<std::string, double> probabilities;
        double totalProbability = 0.0;

        // Assign random probabilities, ensuring they sum close to 1
        for (const auto& concept2 : concepts) {
            double prob = randomDouble(0.0, 1.0, gen); // Random probability
            probabilities[concept2] = prob;
            totalProbability += prob;
        }

        // Normalize probabilities
        for (auto& pair : probabilities) {
            pair.second /= totalProbability;
        }
        transitionMatrix[concept1] = probabilities;
    }
    return transitionMatrix;
}

//Markov Chain Next State
std::string nextState(const std::string& currentState, const std::map<std::string, std::map<std::string, double>>& transitionMatrix, std::mt19937& gen)
{
  std::uniform_real_distribution<> dist(0.0, 1.0);
  double randomValue = dist(gen);
    double cumulativeProbability = 0.0;

    for (const auto& pair : transitionMatrix.at(currentState)) {
        cumulativeProbability += pair.second;
        if (randomValue <= cumulativeProbability) {
            return pair.first; // Return the next state
        }
    }
    return currentState; //Should never reach here in ideal scenarios.
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<std::string> endings;

    // --- 1. Stochastic Sampling ---
    endings.push_back("Coleridge's opium-drenched visions populate my daydreams like " + describeConcept("chaotic", randomDouble(0.0, 1.0, gen), gen));

    // --- 2. Higher-Dimensional Structures ---
    endings.push_back("Coleridge's opium-drenched visions populate my daydreams like " + describeConcept("eigenvector", randomDouble(0.0, 1.0, gen), gen));
    endings.push_back("Coleridge's opium-drenched visions populate my daydreams like " + describeConcept("homotopy", randomDouble(0,1.0, gen), gen));

    // --- 3. Dynamically Constructing Equations ---
    double lambda = randomDouble(0.1, 5.0, gen); // Random λ for Poisson
    std::stringstream ss;
    ss << "Coleridge's opium-drenched visions populate my daydreams following a Poisson process, λ="
       << lambda << " visions per hour, each a fleeting glimpse into the sublime and terrifying.";
    endings.push_back(ss.str());

    // --- 4. Markov Chain Dream Evolution ---
    std::vector<std::string> concepts = {"fractal", "chaotic", "periodic", "singular", "gaussian", "poisson", "eigenvector", "homotopy"};
    std::string lastConcept = "fractal"; // Initial state
    auto transitionMatrix = createTransitionMatrix(gen);

    for (int i = 0; i < 5; ++i) {
        double value = randomDouble(0.0, 1.0, gen);
        //std::string newConcept = concepts[std::rand() % concepts.size()]; // Random selection (old method)
        std::string newConcept = nextState(lastConcept, transitionMatrix, gen); //Using Markov Chain.
        std::stringstream chain_ss;
        chain_ss << "Coleridge's visions transition from a state of '" << lastConcept << "' to " << describeConcept(newConcept, value, gen);
        endings.push_back(chain_ss.str());
        lastConcept = newConcept;
    }


    // Print the generated endings:
    for (const auto& ending : endings) {
        std::cout << ending << std::endl << std::endl;
    }

    return 0;
}
