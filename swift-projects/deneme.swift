print("Hello world!")

let pi = 3.14
let euler: Double = 2.71

func sphericArea(r: Double) -> Double {
    let area = (4/3.0) * pi * (r * r * r)
    return area
}

var name = "Arda"
var age = 21

print(name, "is", String(age), "years old.")
print("\(name) is \(age) years old.")

print(sphericArea(r: 10))
