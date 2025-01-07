#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Category {
public:
    int id;
    string name;

    Category(int id, const string& name) : id(id), name(name) {}

    void display() const {
        cout << left << setw(10) << id << setw(20) << name << endl;
    }
};

class Supplier {
public:
    int id;
    string name;
    string contact;

    Supplier(int id, const string& name, const string& contact) : id(id), name(name), contact(contact) {}

    void display() const {
        cout << left << setw(10) << id << setw(20) << name << setw(20) << contact << endl;
    }
};

class Product {
public:
    int id;
    string name;
    int categoryId;
    int supplierId;
    double price;

    Product(int id, const string& name, int categoryId, int supplierId, double price)
        : id(id), name(name), categoryId(categoryId), supplierId(supplierId), price(price) {}

    void display() const {
        cout << left << setw(10) << id << setw(20) << name << setw(10) << categoryId
             << setw(10) << supplierId << setw(10) << fixed << setprecision(2) << price << endl;
    }
};

class Inventory {
private:
    vector<Category> categories;
    vector<Supplier> suppliers;
    vector<Product> products;
    int nextCategoryId = 1;
    int nextSupplierId = 1;
    int nextProductId = 1;

public:
    void addCategory() {
        string name;
        cout << "Enter category name: ";
        cin.ignore();
        getline(cin, name);
        categories.emplace_back(nextCategoryId++, name);
        cout << "Category added successfully!\n";
    }

    void displayCategories() const {
        if (categories.empty()) {
            cout << "No categories available.\n";
            return;
        }
        cout << left << setw(10) << "ID" << setw(20) << "Name" << endl;
        for (const auto& category : categories) {
            category.display();
        }
    }

    void addSupplier() {
        string name, contact;
        cout << "Enter supplier name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter supplier contact: ";
        getline(cin, contact);
        suppliers.emplace_back(nextSupplierId++, name, contact);
        cout << "Supplier added successfully!\n";
    }

    void displaySuppliers() const {
        if (suppliers.empty()) {
            cout << "No suppliers available.\n";
            return;
        }
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Contact" << endl;
        for (const auto& supplier : suppliers) {
            supplier.display();
        }
    }

    void addProduct() {
        string name;
        int categoryId, supplierId;
        double price;

        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, name);

        displayCategories();
        cout << "Enter category ID: ";
        cin >> categoryId;

        displaySuppliers();
        cout << "Enter supplier ID: ";
        cin >> supplierId;

        cout << "Enter product price: ";
        cin >> price;

        products.emplace_back(nextProductId++, name, categoryId, supplierId, price);
        cout << "Product added successfully!\n";
    }

    void displayProducts() const {
        if (products.empty()) {
            cout << "No products available.\n";
            return;
        }
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Cat. ID"
             << setw(10) << "Sup. ID" << setw(10) << "Price" << endl;
        for (const auto& product : products) {
            product.display();
        }
    }

    void manageInventory() {
        int mainChoice;
        while (true) {
            cout << "\nInventory Management System\n";
            cout << "1. Product Options\n";
            cout << "2. Category Options\n";
            cout << "3. Supplier Options\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> mainChoice;

            switch (mainChoice) {
                case 1: {
                    int productChoice;
                    while (true) {
                        cout << "\n-- Product Options --\n";
                        cout << "1. Add Product\n";
                        cout << "2. Display Products\n";
                        cout << "0. Back\n";
                        cout << "Enter your choice: ";
                        cin >> productChoice;
                        
                        switch (productChoice) {
                            case 1:
                                addProduct();
                                break;
                            case 2:
                                displayProducts();
                                break;
                            case 0:
                                goto mainMenu;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                }
                case 2: {
                    int categoryChoice;
                    while (true) {
                        cout << "\n-- Category Options --\n";
                        cout << "1. Add Category\n";
                        cout << "2. Display Categories\n";
                        cout << "0. Back\n";
                        cout << "Enter your choice: ";
                        cin >> categoryChoice;

                        switch (categoryChoice) {
                            case 1:
                                addCategory();
                                break;
                            case 2:
                                displayCategories();
                                break;
                            case 0:
                                goto mainMenu;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                }
                case 3: {
                    int supplierChoice;
                    while (true) {
                        cout << "\n-- Supplier Options --\n";
                        cout << "1. Add Supplier\n";
                        cout << "2. Display Suppliers\n";
                        cout << "0. Back\n";
                        cout << "Enter your choice: ";
                        cin >> supplierChoice;

                        switch (supplierChoice) {
                            case 1:
                                addSupplier();
                                break;
                            case 2:
                                displaySuppliers();
                                break;
                            case 0:
                                goto mainMenu;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                }
                case 0:
                    cout << "Exiting program. Goodbye!\n";
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
            mainMenu:;
        }
    }
};

int main() {
    Inventory inventory;
    inventory.manageInventory();
    return 0;
}
