//
//  enum.swift
//  
//
//  Created by Arda Türkmenoğlu on 1.08.2025.
//

enum Directions {
    case north
    case south
    case east
    case west
    case none
}

class Room {
    var name: String
    var doorDirection: Directions
    var windowDirection: Directions
    var area: Double
    init(name: String, area: Double, doorDirection: Directions, windowDirection: Directions) {
        self.name = name
        self.doorDirection = doorDirection
        self.windowDirection = windowDirection
        self.area = area
    }
}
class Cellar: Room {
    var numberOfItems: Int
    init(name: String, area: Double, doorDirection: Directions, numberOfItems: Int) {
        self.numberOfItems = numberOfItems
        super.init(name: name, area: area, doorDirection: doorDirection, windowDirection: .none)
    }
}

let ardaRoom = Room(name: "Arda's Room", area: 20, doorDirection: .east, windowDirection: .west)
let cellar = Cellar(name: "Cellar", area: 5, doorDirection: .south, numberOfItems: 75)
print("Arda's Room area is: \(ardaRoom.area)")
print("Cellar area is: \(cellar.area)")
print("Cellar has: \(cellar.numberOfItems) items")
