const {createReadStream, createWriteStream, stat} = require('fs')
const {Transform} = require('stream')

let length = 0
stat('./'+process.argv[2],(e,st)=>{
    length = st.size
    })

fileStream = createReadStream("./"+process.argv[2],"ascii",'r') // produces a stream

bytes = 0;

binaryToBaseTen = new Transform({
transform(chunk, encoding, callback) {
    timer1 = Date.now()
    strArray = []
    chunk.map(char => {strArray.push(char.toString()); /*process.stdout.write('\r' + bytes++ + " of " + length)*/})
    timer2 = Date.now() - timer1
    bytes += chunk.length
    process.stdout.write('\r' + bytes + " of " + length + " bytes/s: " + chunk.length / (timer2 / 1000)) // Slower update but faster write
    /*process.stdout.write(' bytes/s: ' + chunk.length / (timer2 / 1000))
    Uncomment these for faster updates but slower write
    */
    callback(null, strArray.join(" "))
}
})

newFile = createWriteStream("./"+process.argv[2].split('.')[0]+".txt","ascii",'w')

fileStream.pipe(binaryToButts)
binaryToBaseTen.pipe(newFile)