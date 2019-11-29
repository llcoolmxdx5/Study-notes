function _new(fn, ...arg) {
  let obj = Object.create(fn.prototype);
  let ret = fn.apply(obj, arg);
  return ret instanceof Object ? ret : obj;
}

