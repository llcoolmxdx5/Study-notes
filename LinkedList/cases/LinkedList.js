const { defaultEquals } = require("./utils");
const Node = require("./Node");

class LinkedList {
  constructor() {
    this._head = null;
    this.count = 0;
  }
  push(element) {
    const node = new Node(element);
    let current;
    if (this._head === null) {
      this._head = node;
    } else {
      current = this._head;
      while (current.next !== undefined) {
        current = current.next;
      }
      current.next = node;
    }
    this.count += 1;
  }
  getElementAt(index) {
    if (index < 0 || index > this.count) {
      return undefined;
    }
    let node = this._head;
    for (let i = 0; i < index && node !== null; i++) {
      node = node.next;
    }
    return node;
  }
  removeAt(index) {
    if (index < 0 || index >= this.count) {
      return undefined;
    }
    let current = this._head;
    if (index === 0) {
      this._head = current.next;
    } else {
      const previous = this.getElementAt(index - 1);
      current = previous.next;
      previous.next = current.next;
    }
    this.count -= 1;
    return current.element
  }
}

const list = new LinkedList();
list.push(1);
list.push(2);
list.removeAt(0);
