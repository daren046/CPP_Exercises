#include <memory>
#include <vector>
#include <iostream>

struct Product
{
};

struct Client
{
    std::vector<Product *> products;
    ~Client()
    {
        for (auto &product : products)
        {
            delete product;
        }
    }
};

int main()
{
    auto client = Client{};
    client.products.reserve(2);
    client.products.push_back(new Product{});
    client.products.push_back(new Product{});

    auto &first_product = *(client.products.front());
    client.products.push_back(new Product{});

    std::cout << "first product: " << &first_product << std::endl;
    return 0;
}