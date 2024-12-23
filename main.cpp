#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menemukan rating tertinggi secara iteratif
int FindHighestRatedCoffeeShopIteratif(const vector<int>& coffeeShops) {
    int coffeeShopTertinggi = coffeeShops[0]; // Mulai dengan coffee shop pertama

    for (size_t k = 0; k < coffeeShops.size(); ++k) {
        if (coffeeShops[k] > coffeeShopTertinggi) {
            coffeeShopTertinggi = coffeeShops[k]; // Update jika rating lebih tinggi
        }
    }

    return coffeeShopTertinggi; // Kembalikan rating tertinggi
}

// Fungsi untuk menemukan rating tertinggi secara rekursif
int FindHighestRatedCoffeeShopRekursif(const vector<int>& coffeeShops, size_t index) {
    // Basis rekursi: jika sudah di elemen terakhir
    if (index == coffeeShops.size() - 1) {
        return coffeeShops[index];
    }

    // Ambil rating coffee shop saat ini
    int coffeeShopSaatIni = coffeeShops[index];

    // Panggil rekursif untuk elemen berikutnya
    int coffeeShopTertinggiDariSisa = FindHighestRatedCoffeeShopRekursif(coffeeShops, index + 1);

    // Bandingkan rating saat ini dengan rating tertinggi dari sisa daftar
    if (coffeeShopSaatIni > coffeeShopTertinggiDariSisa) {
        return coffeeShopSaatIni;
    } else {
        return coffeeShopTertinggiDariSisa;
    }
}

int main() {
    // Daftar rating coffee shop
    vector<int> coffeeShops = {75, 85, 90, 60, 95, 80};

    // Mencari rating tertinggi secara iteratif
    int highestIterative = FindHighestRatedCoffeeShopIteratif(coffeeShops);
    cout << "Rating tertinggi (Iteratif): " << highestIterative << endl;

    // Mencari rating tertinggi secara rekursif
    int highestRecursive = FindHighestRatedCoffeeShopRekursif(coffeeShops, 0);
    cout << "Rating tertinggi (Rekursif): " << highestRecursive << endl;

    return 0;
}
