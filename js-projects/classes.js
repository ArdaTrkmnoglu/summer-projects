class Animal {
    alive = true;

    eat() {
        console.log(`This ${this.name} is eating.`);
    }
    sleep() {
        console.log(`This ${this.name} is sleeping.`);
    }
}
class Rabbit extends Animal {
    name = "rabbit";

    run() {
        console.log(`This ${this.name} is running.`);
    }
}
class Fish extends Animal {
    name = "fish";

    swim() {
        console.log(`This ${this.name} is swimming.`);
    }
}

const rabbit = new Rabbit();
const fish = new Fish();

console.log(fish.alive);
fish.eat();
fish.sleep();
fish.swim();
rabbit.run();
