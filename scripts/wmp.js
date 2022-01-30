const fs = require('fs');
const path = require('path');

const input = '../index.js'

const text = fs.readFileSync(path.join(__dirname, input), 'utf-8')

const converted = text.replace(/WebAssembly/g, 'WXWebAssembly').replace('self.location.href', '(self || this).location.href').replace(/return getBinaryPromise\(\)\.then\(.+?\}\)/s, `return WXWebAssembly.instantiate('/pages/wasm/hello.wasm', info)`).replace('instantiateAsync();', 'instantiateArrayBuffer(receiveInstantiationResult);');

const result = fs.writeFileSync('hello.js', converted);

console.log('text = ', result)