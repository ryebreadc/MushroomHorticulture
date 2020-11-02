#include <iostream>
using namespace std;

class basketOfMushrooms {
  int quantity;
  int weight;
  string strain;

  public:

    basketOfMushrooms(string set_strain) {
      strain = set_strain;
    }
    void setWeight(int set_weight) {
      weight = set_weight;
    }
    void setQuantity(int set_quantity) {
      quantity = set_quantity;
    }
    string getStrain() {
      return strain;
    }
    int getWeight() {
      return weight;
    }
    int getQuantity() {
      return quantity;
    }

    void show() {
      cout << "Strain: " << strain << endl;
      cout << "Quantity: " << quantity << endl;
      cout << "Weight: " << weight << endl;
    }

};

class mushroomGrower {

  protected:
    basketOfMushrooms *basket;
  public:
    virtual void getMushroom() = 0;
    virtual void buildQuantity() = 0;
    virtual void buildWeight() = 0;
    basketOfMushrooms* getBasket() {
      return basket;
    }

};

class fruitingChamber: public mushroomGrower {
  public:
    void getMushroom() {
      basket = new basketOfMushrooms("Shiitake");
    }
    void buildQuantity() {
      basket->setQuantity(10);
    }
    void buildWeight() {
      basket->setWeight(5);
    }
};

class monotub: public mushroomGrower {
  public:
     void getMushroom() {
       basket = new basketOfMushrooms("Cordyceps");
     }
     void buildQuantity() {
       basket->setQuantity(25);
     }
     void buildWeight() {
       basket->setWeight(7);
     }
};

class spawnBag: public mushroomGrower {
  public:
    void getMushroom() {
      basket = new basketOfMushrooms("Reishi");
    }
    void buildQuantity() {
      basket->setQuantity(4);
    }
    void buildWeight() {
      basket->setWeight(8);
    }
};

class Director {
  mushroomGrower *grower;

  public:
    basketOfMushrooms* growBasketOfMushrooms(mushroomGrower *grower) {
      grower->getMushroom();
      grower->buildQuantity();
      grower->buildWeight();
      return grower->getBasket();
    }
};

int main() {
  Director dir;
  monotub mt;
  spawnBag sb;
  fruitingChamber fc;

  basketOfMushrooms *tub = dir.growBasketOfMushrooms(&mt);
  basketOfMushrooms *bag = dir.growBasketOfMushrooms(&sb);
  basketOfMushrooms *chamber = dir.growBasketOfMushrooms(&fc);

  tub->show();
  delete tub;

  bag->show();
  delete bag;

  chamber->show();
  delete chamber;

  return 0;
}