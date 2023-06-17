import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.FileReader
import java.io.OutputStreamWriter
import java.lang.Math.max
import java.lang.Math.min

fun <T> read(reader: BufferedReader, mapper: String.() -> T): T {
    return reader.readLine().mapper()
}

fun <T> readList(reader: BufferedReader, separator: String = " ", mapper: String.() -> T): List<T> {
    return reader.readLine().split(separator).map(mapper)
}

fun readList(reader: BufferedReader, separator: String = " "): List<String> {
    return reader.readLine().split(separator)
}

data class Node(
    val left: Int = 0,
    val right: Int = 0,
    var lNode: Node? = null,
    var rNode: Node? = null,
    var subsum: Int = 0,
    var max: Int = 0
)

class SegTree(var array: Array<Int>) {
    private var root: Node = build(0, array.lastIndex)

    private fun build(l: Int, r: Int): Node {
        val tempRoot = Node(l, r)
        if (l == r) {
            tempRoot.max = array[l]
            return tempRoot
        }
        tempRoot.lNode = build(l, (l + r) / 2)
        tempRoot.rNode = build((l + r) / 2 + 1, r)
        return tempRoot
    }

    fun update(l: Int, r: Int) {
        update(root, l, min(r, root.right))
    }

    fun getMax(l: Int, r: Int): Int {
        return getMax(root, l, r)
    }

    private fun update(tempRoot: Node, l: Int, r: Int) { // +1 на отрезке
        if (l > tempRoot.right || tempRoot.left > r) {
            return
        }
        if (tempRoot.left >= l && tempRoot.right <= r) {
            tempRoot.subsum++
            tempRoot.max++
        } else {
            if (tempRoot.lNode != null)
                update(tempRoot.lNode!!, l, r)
            if (tempRoot.rNode != null)
                update(tempRoot.rNode!!, l, r)
            tempRoot.max = max((tempRoot.lNode?.max ?: 0), (tempRoot.rNode?.max ?: 0)) + tempRoot.subsum
        }
    }


    private fun getMax(tempRoot: Node, l: Int, r: Int): Int { // максимум на отрезке
        if (l > tempRoot.right || tempRoot.left > r) {
            return 0
        }
        if (tempRoot.left >= l && tempRoot.right <= r) {
            return tempRoot.max
        } else {
            val lMax =
                if (tempRoot.lNode != null) getMax(tempRoot.lNode!!, l, r)
                else 0
            val rMax =
                if (tempRoot.rNode != null) getMax(tempRoot.rNode!!, l, r)
                else 0

            return max(lMax, rMax) + tempRoot.subsum
        }
    }
}

fun solve(reader: BufferedReader, writer: BufferedWriter) {
    val (n, s, t) = readList(reader) { toInt() }
    val times = readList(reader) { toInt() }
    val maxTime = times.maxOf { it }
    val array = Array(maxTime + 1) { 0 }
    val segTree = SegTree(array)

    for (time in times) {
        val max = segTree.getMax(time, time + t - 1)
        if (max + 1 <= s) {
            writer.write("YES\n")
            segTree.update(time, time + t - 1)
/*            for (i in 0 until maxTime) {
                writer.write("${DOTree.getMax(i, i)} ")
            }
            writer.write("\n")*/
        } else {
            writer.write("NO\n")
/*            for (i in 0 until maxTime) {
                writer.write("${DOTree.getMax(i, i)} ")
            }
            writer.write("\n")*/
        }
    }
}

fun main(args: Array<String>) {
    val reader = BufferedReader(FileReader("input.txt"))
    val writer = BufferedWriter(OutputStreamWriter(System.out))

    solve(reader, writer)

    reader.close()
    writer.close()
}
