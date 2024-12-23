#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struct untuk menyimpan data coffee shop
struct CoffeeShop {
    string name;
    int rating;
};

// Fungsi untuk menemukan coffee shop dengan rating tertinggi secara iteratif
string FindHighestRatedCoffeeShopIteratif(const vector<CoffeeShop>& coffeeShops) {
    CoffeeShop coffeeShopTertinggi = coffeeShops[0]; // Mulai dengan coffee shop pertama

    for (size_t k = 0; k < coffeeShops.size(); ++k) {
        if (coffeeShops[k].rating > coffeeShopTertinggi.rating) {
            coffeeShopTertinggi = coffeeShops[k]; // Update jika rating lebih tinggi
        }
    }

    return coffeeShopTertinggi.name; // Kembalikan nama coffee shop dengan rating tertinggi
}

// Fungsi untuk menemukan coffee shop dengan rating tertinggi secara rekursif
CoffeeShop FindHighestRatedCoffeeShopRekursif(const vector<CoffeeShop>& coffeeShops, size_t index) {
    // Basis rekursi: jika sudah di elemen terakhir
    if (index == coffeeShops.size() - 1) {
        return coffeeShops[index];
    }

    // Panggil rekursif untuk elemen berikutnya
    CoffeeShop coffeeShopTertinggiDariSisa = FindHighestRatedCoffeeShopRekursif(coffeeShops, index + 1);

    // Bandingkan rating saat ini dengan rating tertinggi dari sisa daftar
    if (coffeeShops[index].rating > coffeeShopTertinggiDariSisa.rating) {
        return coffeeShops[index];
    } else {
        return coffeeShopTertinggiDariSisa;
    }
}

int main() {
    // Daftar coffee shop di Bandung beserta ratingnya
    vector<CoffeeShop> coffeeShops = {
        {"Kopi Tuku", 85},
        {"Kopi Kenangan", 90},
        {"Janji Jiwa", 95},
        {"Starbucks", 80},
        {"Fore Coffee", 88}
    };

    // Mencari coffee shop dengan rating tertinggi secara iteratif
    string highestIterative = FindHighestRatedCoffeeShopIteratif(coffeeShops);
    cout << "Coffee shop dengan rating tertinggi (Iteratif): " << highestIterative << endl;

    // Mencari coffee shop dengan rating tertinggi secara rekursif
    CoffeeShop highestRecursive = FindHighestRatedCoffeeShopRekursif(coffeeShops, 0);
    cout << "Coffee shop dengan rating tertinggi (Rekursif): " << highestRecursive.name << endl;

    return 0;
}
