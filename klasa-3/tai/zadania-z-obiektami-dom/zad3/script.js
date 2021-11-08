const hexadecimalChars = "1234567890abcdef".split("")
let changeColorButton = document.getElementById("changeColor")

const onChangeColorButtonClicked = () => {
    let color = "#"

    for (let i = 0; i < 6; i++) {
        color += hexadecimalChars[Math.floor(Math.random() * hexadecimalChars.length)]
    }

    document.body.style.backgroundColor = color
}

changeColorButton.addEventListener("click", onChangeColorButtonClicked)