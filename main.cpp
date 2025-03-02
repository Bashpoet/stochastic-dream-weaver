#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <sstream>
#include <map>
#include <functional>
#include <memory>
#include <Eigen/Dense>

// --- Constants and Type Definitions ---

// Define available concepts
const std::vector<std::string> CONCEPTS = {
    "fractal", "chaotic", "periodic", "singular", 
    "gaussian", "poisson", "eigenvector", "homotopy",
    "lagrangian", "manifold", "entropy"  // Added new concepts
};

// Using aliases for readability
using TransitionMatrix = std::map<std::string, std::map<std::string, double>>;
using ConceptDescriber = std::function<std::string(double, std::mt19937&)>;

// --- Helper Functions ---

// Function to generate a random double within a range
double randomDouble(double min, double max, std::mt19937& gen) {
    std::uniform_real_distribution<> dist(min, max);
    return dist(gen);
}

// --- Concept Description Functions ---

// Each concept gets its own description function for better organization
std::string describeFractal(double value, std::mt19937& gen) {
    std::stringstream ss;
    ss << "fractal blooms, each iteration revealing " 
       << (value > 0.5 ? "more vibrant detail, like the infinite coastline of a dream" 
                       : "deeper, swirling chaos, a Mandelbrot set of memories");
    return ss.str();
}

std::string describeExponential(double value, std::mt19937& gen) {
    std::stringstream ss;
    ss << "an exponential surge, the intensity growing " 
       << (value > 0.5 ? "to an ecstatic peak, doubling with each heartbeat" 
                       : "towards an overwhelming oblivion, consciousness halving with each breath");
    return ss.str();
}

std::string describeChaotic(double value, std::mt19937& gen) {
    std::stringstream ss;
    ss << "a chaotic dance, where " 
       << (value > 0.5 ? "patterns briefly emerge from the noise, like fleeting recognitions" 
                       : "disorder reigns supreme, sensitive to initial conditions of thought");
    return ss.str();
}

std::string describePeriodic(double value, std::mt19937& gen) {
    std::stringstream ss;
    ss << "periodic waves, cresting and falling with the rhythm of " 
       << (value > 0.5 ? "a fevered pulse, syncopated with celestial harmonies" 
                       : "a slowly fading heartbeat, each cycle diminishing into silence");
    return ss.str();
}

std::string describeSingular(double value, std::mt19937& gen) {
    std::stringstream ss;
    ss << "singularities, points of infinite density where " 
       << (value > 0.5 ? "reality itself fractures along hyperbolic geometries" 
                       : "consciousness dissolves into a point of pure, dimensionless being");
    return ss.str();
}

std::string describeGaussian(double value, std::mt19937& gen) {
    std::stringstream ss;
    ss << "a Gaussian blur, where clarity peaks at the center and fades into " 
       << (value > 0.5 ? "a hazy, dreamlike periphery of half-remembered sensations" 
                       : "an indistinct, ethereal mist where certainty dissipates with distance");
    return ss.str();
}

std::string describePoisson(double value, std::mt19937& gen) {
    double lambda = randomDouble(0.1, 5.0, gen);
    std::stringstream ss;
    ss << "a Poisson distribution of phantasms, appearing with λ=" << std::fixed << std::setprecision(2) << lambda 
       << " visions per hour, like " 
       << (value > 0.5 ? "sparks from a dying ember, each a discrete moment of illumination" 
                       : "glimmers in the deepest ocean, rare and unpredictable yet statistically governed");
    return ss.str();
}

std::string describeEigenvector(double value, std::mt19937& gen) {
    // Generate a random covariance matrix and find its eigenvectors
    Eigen::MatrixXd cov(3, 3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cov(i, j) = randomDouble(-1, 1, gen);
        }
    }
    cov = cov * cov.transpose(); // Ensure positive semi-definite
    Eigen::EigenSolver<Eigen::MatrixXd> es(cov);
    Eigen::VectorXcd evec = es.eigenvectors().col(0); // Take the first eigenvector

    std::stringstream ss;
    ss << "eigenvectors of a shimmering covariance matrix, principal components whispering forgotten stanzas "
       << "from the stochastic depths of Xanadu. The dominant eigenvector, ("
       << std::fixed << std::setprecision(2) << evec(0).real() << ", " 
       << evec(1).real() << ", " << evec(2).real() 
       << "), guides the dream's trajectory through the subspace of memory.";
    return ss.str();
}

std::string describeHomotopy(double value, std::mt19937& gen) {
    int numLoops = static_cast<int>(randomDouble(1, 5, gen));
    std::stringstream ss;
    ss << "homotopy classes winding through the labyrinth of cognition, where each of the " << numLoops 
       << " loops is a recursion into forgotten poetry, a topological knot in the fabric of consciousness, "
       << (value > 0.5 ? "continuously deformable yet fundamentally invariant" 
                       : "preserving the essential structure across transformations of perception");
    return ss.str();
}

// New concept: Lagrangian mechanics
std::string describeLagrangian(double value, std::mt19937& gen) {
    std::stringstream ss;
    double energy = randomDouble(1.0, 10.0, gen);
    ss << "a Lagrangian system seeking the path of least action through the phase space of memory, "
       << "with total energy " << std::fixed << std::setprecision(2) << energy << " units, "
       << (value > 0.5 ? "following geodesics across the curved manifold of consciousness" 
                       : "conserving the difference between kinetic thought and potential insight");
    return ss.str();
}

// New concept: Manifold
std::string describeManifold(double value, std::mt19937& gen) {
    int dimensions = static_cast<int>(randomDouble(3, 11, gen));
    std::stringstream ss;
    ss << "a " << dimensions << "-dimensional manifold, locally resembling Euclidean space but globally "
       << (value > 0.5 ? "twisted into exotic topologies where memories connect across impossible distances" 
                       : "folded back upon itself, creating self-references and recursive structures of thought");
    return ss.str();
}

// New concept: Entropy
std::string describeEntropy(double value, std::mt19937& gen) {
    double entropyValue = randomDouble(0.1, 1.0, gen);
    std::stringstream ss;
    ss << "an entropic system with " << std::fixed << std::setprecision(2) << entropyValue 
       << " bits of information loss per second, "
       << (value > 0.5 ? "disorder increasing as the arrow of time pushes consciousness forward" 
                       : "memories dissolving into statistical noise, the inevitable heat death of perfect recall");
    return ss.str();
}

// Map of concept names to their description functions
std::map<std::string, ConceptDescriber> createConceptMap() {
    return {
        {"fractal", describeFractal},
        {"exponential", describeExponential},
        {"chaotic", describeChaotic},
        {"periodic", describePeriodic},
        {"singular", describeSingular},
        {"gaussian", describeGaussian},
        {"poisson", describePoisson},
        {"eigenvector", describeEigenvector},
        {"homotopy", describeHomotopy},
        {"lagrangian", describeLagrangian},
        {"manifold", describeManifold},
        {"entropy", describeEntropy}
    };
}

// Master function to describe a concept
std::string describeConcept(const std::string& concept, double value, std::mt19937& gen) {
    static const auto conceptMap = createConceptMap();
    
    auto it = conceptMap.find(concept);
    if (it != conceptMap.end()) {
        return it->second(value, gen);
    }
    
    // Fallback for unknown concepts
    return "undefined mathematical patterns beyond current comprehension";
}

// --- Markov Chain Implementation ---

// Create a transition matrix with balanced probabilities
TransitionMatrix createTransitionMatrix(std::mt19937& gen) {
    TransitionMatrix transitionMatrix;

    for (const auto& concept1 : CONCEPTS) {
        std::map<std::string, double> probabilities;
        double totalProbability = 0.0;

        // Assign random probabilities
        for (const auto& concept2 : CONCEPTS) {
            double prob = randomDouble(0.0, 1.0, gen);
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

// Determine the next state in the Markov chain
std::string nextState(const std::string& currentState, const TransitionMatrix& transitionMatrix, std::mt19937& gen) {
    std::uniform_real_distribution<> dist(0.0, 1.0);
    double randomValue = dist(gen);
    double cumulativeProbability = 0.0;

    for (const auto& pair : transitionMatrix.at(currentState)) {
        cumulativeProbability += pair.second;
        if (randomValue <= cumulativeProbability) {
            return pair.first;
        }
    }
    
    // Fallback - should rarely happen
    return CONCEPTS[0];
}

// --- Output Generators ---

// Generate a basic vision based on a concept
std::string generateVision(const std::string& concept, std::mt19937& gen) {
    double value = randomDouble(0.0, 1.0, gen);
    std::stringstream ss;
    ss << "Coleridge's opium-drenched visions populate my daydreams like " 
       << describeConcept(concept, value, gen);
    return ss.str();
}

// Generate a Poisson process description
std::string generatePoissonProcess(std::mt19937& gen) {
    double lambda = randomDouble(0.1, 5.0, gen);
    std::stringstream ss;
    ss << "Coleridge's opium-drenched visions populate my daydreams following a Poisson process, λ="
       << std::fixed << std::setprecision(2) << lambda 
       << " visions per hour, each a fleeting glimpse into the sublime and terrifying.";
    return ss.str();
}

// Generate a transition description
std::string generateTransition(const std::string& fromConcept, const std::string& toConcept, std::mt19937& gen) {
    double value = randomDouble(0.0, 1.0, gen);
    std::stringstream ss;
    ss << "Coleridge's visions transition from a state of '" << fromConcept << "' to " 
       << describeConcept(toConcept, value, gen);
    return ss.str();
}

// --- Main Function ---

int main() {
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<std::string> outputs;
    
    // Generate various types of outputs
    
    // 1. Simple vision descriptions
    outputs.push_back(generateVision("chaotic", gen));
    outputs.push_back(generateVision("eigenvector", gen));
    outputs.push_back(generateVision("homotopy", gen));
    
    // 2. Poisson process description
    outputs.push_back(generatePoissonProcess(gen));
    
    // 3. Markov chain evolution
    std::string currentConcept = CONCEPTS[0]; // Start with fractal
    auto transitionMatrix = createTransitionMatrix(gen);
    
    const int chainLength = 5;
    for (int i = 0; i < chainLength; ++i) {
        std::string nextConcept = nextState(currentConcept, transitionMatrix, gen);
        outputs.push_back(generateTransition(currentConcept, nextConcept, gen));
        currentConcept = nextConcept;
    }
    
    // Print all generated outputs with nice formatting
    std::cout << "=======================================" << std::endl;
    std::cout << "  STOCHASTIC POETIC VISIONS GENERATOR  " << std::endl;
    std::cout << "=======================================" << std::endl << std::endl;
    
    for (size_t i = 0; i < outputs.size(); ++i) {
        std::cout << i+1 << ". " << outputs[i] << std::endl << std::endl;
    }
    
    return 0;
}
