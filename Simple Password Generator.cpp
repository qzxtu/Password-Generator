#include <iostream>
#include <string>
#include <random>
#include <chrono>

// Genera una contraseña aleatoria a partir de una secuencia de caracteres y una longitud
std::string generate_password(const std::string& character_sequence, const std::size_t password_length)
{
    std::string password{};
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count()); // Generador de números aleatorios seguro

    std::size_t sequence_length = character_sequence.size();
    std::uniform_int_distribution<std::size_t> distribution(0, sequence_length - 1); // Distribución uniforme para generar índices aleatorios en la secuencia

    // Genera cada carácter de la contraseña aleatoriamente a partir de la secuencia de caracteres
    for (std::size_t i = 0; i < password_length; i++)
        password += character_sequence[distribution(rng)];

    return password;
}

int main()
{
    const std::string CHARACTER_SEQUENCE{ "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    const std::size_t PASSWORD_LENGTH = 16;

    std::string password = generate_password(CHARACTER_SEQUENCE, PASSWORD_LENGTH); // Genera la contraseña

    std::cout << "Tu contraseña es: " << password << '\n';
    std::cin.get();

    return EXIT_SUCCESS;
}