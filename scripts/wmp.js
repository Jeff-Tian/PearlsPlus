const fs = require('fs');
const path = require('path');

console.log('args = ', process.argv);
console.log('working = ', __dirname);
console.log('cwd = ', process.cwd());

const input = process.argv[2] || 'index.js'

const file = path.join(process.cwd(), input)
const convertedFile = path.join(process.cwd(), input + '.converted')
const eval5File = path.join(process.cwd(), input + '.eval5')

console.log('handling ', file)

const text = fs.readFileSync(file, 'utf-8')

// if (text.includes('WXWebAssembly')) {
//     console.log('skip ', file, ' as it is already converted.')
// }

const converted = text.replace(/WebAssembly/g, 'WXWebAssembly').replace('self.location.href', '(self || this).location.href').replace(/return getBinaryPromise\(\)\.then\(.+?\}\)/s, `return WXWebAssembly.instantiate(this.wasmPath, info)`).replace('instantiateAsync();', 'instantiateArrayBuffer(receiveInstantiationResult);').replace(`var Module = typeof Module !== 'undefined' ? Module : {};`, `var Module = typeof this.Module !== 'undefined' ? this.Module : {};`);

const eval5 = text.replace(/WebAssembly/g, 'WXWebAssembly').replace('self.location.href', '(self || global).location.href').replace(/return getBinaryPromise\(\)\.then\(.+?\}\)/s, `return WXWebAssembly.instantiate(global.wasmPath, info)`).replace('instantiateAsync();', 'instantiateArrayBuffer(receiveInstantiationResult);').replace(`var Module = typeof Module !== 'undefined' ? Module : {};`, `var Module = typeof global.Module !== 'undefined' ? global.Module : {};`);

fs.writeFileSync(convertedFile, converted);
fs.writeFileSync(eval5File, eval5);