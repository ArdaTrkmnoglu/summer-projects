//
//  arda.swift
//  
//
//  Created by Arda Türkmenoğlu on 20.07.2025.
//


let ardaString = "Arda & Ayda"
print("\(ardaString): ", terminator: "")

for codeUnit in ardaString.unicodeScalars {
    print("\(codeUnit.value) ", terminator: "")
}
print("")


var integers: [Int] = []
integers.append(31)
print(integers)

var letters = Set<Character>()
letters.insert("a")
print("The letters set has \(letters.count) elements")

var idAndStudent: [Int: String] = [:]
idAndStudent[1] = "Arda"
idAndStudent[2] = "Ayda"
print("\(idAndStudent[1]!) and \(idAndStudent[2]!) will be married someday.")

var ituIdAndStudent: [Int:String] = [150230056: "Arda", 150230098: "Ayda"]
print(ardaString + " is \(ituIdAndStudent[150230056] ?? "not found") and \(ituIdAndStudent[150230098] ?? "not found")")

var airports = ["IAD": "Washington Dulles International Airport", "JFK": "John F. Kennedy International Airport", "LHR": "London Heathrow Airport", "SFO": "San Francisco International Airport", "IST": "Istanbul Airport", "ASR": "Kayseri Erkilet Airport", "COV": "Mersin Çukurova Airport"]

for (airportCode, airportName) in airports {
    print(airportCode + ": " + airportName)
}
