class EventEmitter {
    eventMap = {}; //event  -> [list of callbacks]
    subscribe(event, cb) {
        if(!this.eventMap.hasOwnProperty(event)){
            this.eventMap[event] = new Set();
        }
        this.eventMap[event].add(cb); // storing callbacks as a list
      return {
          unsubscribe: () => {
            this.eventMap[event].delete(cb); // deleting callback from the list
          }
      };
    }
  
    emit(event, args = []) {
        const res =[];
        (this.eventMap[event] ?? []).forEach(cb => res.push(cb(...args)));
        return res;
    }
  }
/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
