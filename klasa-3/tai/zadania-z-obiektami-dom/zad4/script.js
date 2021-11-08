let countInput = document.getElementById("count")
let generateButton = document.getElementById("generate")

const fibonacci = (length) => length < 1 ? 0: length <= 2 ? 1: fibonacci(length - 1) + fibonacci(length - 2)

const onGenerateClicked = () => {
    document.getElementById("result").innerText = fibonacci(countInput.value) 
}

generateButton.addEventListener("click", onGenerateClicked)
