//
//  closures_sorting.swift
//
//
//  Created by Arda Türkmenoğlu on 1.08.2025.
//

let names = ["Arda", "Ayda", "Ada", "Neva"]

// func sortBackwards(_ s1: String, _ s2: String) -> Bool {
//     return s1 > s2
// }

// var sortedNames = names.sorted(by: {(_ s1: String, _ s2: String) -> Bool in return s1 > s2})
// var sortedNames = names.sorted(by: {s1, s2 in return s1 > s2})
var sortedNames = names.sorted(by: {s1, s2 in s1 > s2})

print(names)
print(sortedNames)
print(names.sorted())
