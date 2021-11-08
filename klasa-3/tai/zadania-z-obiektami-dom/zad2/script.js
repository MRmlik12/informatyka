let numbersToSortInput = document.getElementById("numbersToSort")
let sortButton = document.getElementById("sort")

const onSortButtonClicked = () => {
    const numbersToSort = numbersToSortInput.value.split(", ")

    console.log(numbersToSort)
    document.getElementById("result").innerText = numbersToSort.sort((a, b) => a - b).toString()
}

sortButton.addEventListener("click", onSortButtonClicked)