// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;

contract EscrowContract {
    address payable public buyer;
    address payable public seller;
    address public escrow;

    constructor(address payable  _buyer, address payable  _seller) {
        buyer = _buyer;
        seller = _seller;
        escrow = msg.sender;
    }

    function releaseFundsToSeller() public  {
        require(msg.sender == escrow);
        seller.transfer(address(this).balance);
    }

    function refundFundsToBuyer() public {
        require(msg.sender == escrow);
        buyer.transfer(address(this).balance);
    }

    function depositFunds() public payable {
        require(msg.sender == buyer);
    }

    function getBalance() public view returns (uint256) {
        return address(this).balance;
    }
}