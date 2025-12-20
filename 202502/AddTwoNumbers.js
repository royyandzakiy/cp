/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
*/
 
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

// 1 -> 2 -> 3
la_3 = new ListNode(3,undefined)
la_2 = new ListNode(4,la_3)
la_1 = new ListNode(2,la_2)
la = la_1

// 4 -> 5 -> 6 -> 7
lb_3 = new ListNode(4,undefined)
lb_2 = new ListNode(6,lb_3)
lb_1 = new ListNode(5,lb_2)
lb = lb_1

var addTwoNumbers = function(l1, l2) {
    //     /**
    //     - convert into number
    //       - [1,2,3] = 1 + 20 + 300
    //       - 1 = (((321 % 10) / 1) * 1); 20 = ((321 % 100) / 10) * 10
    //       - 
    //       - numTotal += arrItem * 10 ^ pos
    //       - pos++
    //       - for arr.length
    //       - 
    //     - do addition
    //     - revert into arr
    //      */

    let num1 = linkedToNum(l1)
    let num2 = linkedToNum(l2)
    let numTotal = num1 + num2;

    console.log(num1)
    console.log(num2)
    console.log(numTotal)

    return numToLinked(numTotal)
}

function linkedToNum(l) {
    let num = 0
    let pos = 0

    while(l.next != undefined) {
        num += l.val * Math.pow(10, pos)
        pos++
        l = l.next
    }

    num += l.val * Math.pow(10, pos)

    return num
}

function numToLinked(n) {
    // get pow
    // get num divide by pow
        // 123
        // 3 = 123 % 10 ^ 1 / 10 ^ 0 
        // 2 = 123 % 10 ^ 2 / 10 ^ 1
        // 1 = 123 % 10 ^ 3 / 10 ^ 2 < first
    
    let pow = 0
    while(Math.round(n / Math.pow(10, pow + 1)) != 0) {
        pow++
    }

    let val = n
    let l_head = undefined
    let l = new ListNode(val, l_head)

    for (let i=pow; i>=0; i--) {
        val = Math.round((n % Math.pow(10, i + 1)) / Math.pow(10, i))
        l = new ListNode(val, l_head)
        n = n % Math.pow(10, i)
        l_head = l

        console.log("n = " + n)
        console.log("pow = " + i)
        console.log("l_head.val = " + val)
        console.log("-----")
    }

    return l // should be the first node
}

// addTwoNumbers(la, lb)
console.log(addTwoNumbers(la, lb))
